#pragma once

#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "BitMap.hpp"
#include "Directory.hpp"

const short g_BlockSize = 64;
const short g_NumBlocks = 128;
const short g_NumInodes = 32;
const short g_MaxNumBlock = 13;
const short g_MaxFileSize = g_MaxNumBlock * g_BlockSize;

const int g_InodeBitMapSize = ((g_NumInodes + g_NumBitsInWord - 1) / g_NumBitsInWord) * sizeof(int);
const int g_BlockBitMapSize = ((g_NumBlocks + g_NumBitsInWord - 1) / g_NumBitsInWord) * sizeof(int);

struct SInode {
    char FileType;                    //'f'???????????'d'????????
    short FileSize;
    short NumBlocks;
    short NumLinks;
    short BlockNums[g_MaxNumBlock];
};

struct SOpenFile {
    short InodeNum;
    int CurSeekPos;                  //?洢?????д??λ??
    SInode Inode;
};

const int g_DiskSize = g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes + g_BlockSize * g_NumBlocks;
extern char g_Disk[g_DiskSize];


int readDataFromFile(void *vDestination, int vNumBytes, SOpenFile &vioFile) {
    int FileLength = vioFile.Inode.FileSize;
    if ((vNumBytes <= 0) || (vioFile.CurSeekPos >= FileLength)) return 0;   //读取到了文件末尾
    if ((vioFile.CurSeekPos + vNumBytes) > FileLength) vNumBytes = FileLength - vioFile.CurSeekPos;//防越界

    int FirstBlock =
            vioFile.CurSeekPos / g_BlockSize;                      //计算起始和末尾的数据块，这里计算的结果表示Inode.BlockNums[]数组中的下标范围
    int LastBlock = (vioFile.CurSeekPos + vNumBytes - 1) / g_BlockSize;       //包含curseekpos指向的一块
    int NumBlocks = 1 + LastBlock - FirstBlock;

    char *pDiskDataPos = g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes;//指向内存起始
    char *pBuff = new char[NumBlocks * g_BlockSize];//缓冲区
    char *pTemp = pBuff;//防止移动pBuff指针
    for (int i = FirstBlock; i <= LastBlock; ++i)//读出文件全部内容
    {
        memmove(pTemp, pDiskDataPos + g_BlockSize * vioFile.Inode.BlockNums[i], g_BlockSize);
        pTemp += g_BlockSize;
    }

    memmove(vDestination, &pBuff[vioFile.CurSeekPos % g_BlockSize], vNumBytes);//pBuff为字符数组
    delete[] pBuff;
    vioFile.CurSeekPos += vNumBytes;
    return vNumBytes;
}

int writefile(const SDirectory &sourece, int byte, SOpenFile &file) {
    if (byte <= 0)
        return 0;
    if (file.CurSeekPos + byte > g_MaxFileSize)            //超过最大长度
        byte = g_MaxFileSize - file.CurSeekPos;
    if (file.CurSeekPos + byte > file.Inode.FileSize) {  //超过分配大小
        SBitMap DataBlockBitMap;
        createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
        memmove(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);
        int nums = (file.CurSeekPos + byte - file.Inode.FileSize) / g_BlockSize;
        int i = 0;
        while (i < nums) {
            file.Inode.BlockNums[file.Inode.NumBlocks] = findAndSetAvailableBit(DataBlockBitMap);
            file.Inode.NumBlocks++;
            i++;
        }
        memmove(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);//写回虚拟硬盘
    }
    int block =
            file.CurSeekPos / g_BlockSize;
    int finalBlock = (file.CurSeekPos + byte - 1) / g_BlockSize;
    int numfBlocks = 1 + finalBlock - block;

    char *pos = g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes; //指向起始位置
    char *buff = new char[numfBlocks * g_BlockSize];
    char *temp = buff;
    int i = block;
    while (i <= finalBlock) { //读出内容
        memmove(temp, pos + g_BlockSize * file.Inode.BlockNums[i], g_BlockSize);
        temp += g_BlockSize;
        i++;
    }
    memmove(buff, (char *) &sourece, byte);
    temp = buff;
    i = block;
    while (i <= finalBlock) {
        memmove(pos + g_BlockSize * file.Inode.BlockNums[i], temp, g_BlockSize);
        temp += g_BlockSize;
        i++;
    }
    file.CurSeekPos += byte;
    delete[]buff;
    return byte;
}

SInode loadInodeFromDisk(int vInodeNum) {
    SInode DirInode{};
    memmove(&DirInode, g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * vInodeNum, sizeof(SInode));

    return DirInode;
}


SDirectory loadDirectoryFromDisk(int vDirInodeNum) {
    //return g_RootDir;        //这里先用全局变量保存Dir，等实现了文件读写再来完成
    SOpenFile DirOpenFile{};
    DirOpenFile.CurSeekPos = 0;
    DirOpenFile.InodeNum = vDirInodeNum;
    DirOpenFile.Inode = loadInodeFromDisk(vDirInodeNum);     //根据INode编号，读取目录的Inode信息
    assert(DirOpenFile.Inode.FileType == 'd');//检察语句，为假则中止执行

    SDirectory TempDir{};
    readDataFromFile(&TempDir, sizeof(SDirectory), DirOpenFile);

    return TempDir;
}

bool allocateDisk(SInode &voInode, int vFileSize, SBitMap &vioBlockBitMap) {
    voInode.FileSize = vFileSize;
    voInode.NumLinks = 1;
    voInode.NumBlocks = (int) ceil(vFileSize / (double) g_BlockSize);//ceil：向上取整

    if (countClearBits(vioBlockBitMap) < voInode.NumBlocks) return false;//剩余位数少于请求位数

    for (int i = 0; i < voInode.NumBlocks; ++i)
        voInode.BlockNums[i] = findAndSetAvailableBit(vioBlockBitMap);//随机分配->最近的一个
    for (int i = voInode.NumBlocks; i < g_MaxNumBlock; ++i) voInode.BlockNums[i] = -1;//未被用到的部分置-1

    return true;
}

void saveDirectory2Disk(int vDirInodeNum, const SDirectory &vDirectory) {
    //g_RootDir = vDirectory;   //这里也是用全局的变量保存目录，等实现了文件读写再来完成
    SOpenFile DirOpenFile{};
    DirOpenFile.CurSeekPos = 0;
    DirOpenFile.InodeNum = vDirInodeNum;
    DirOpenFile.Inode = loadInodeFromDisk(vDirInodeNum);     //根据INode编号，读取目录的Inode信息
    assert(DirOpenFile.Inode.FileType == 'd');
    writefile(vDirectory, sizeof(SDirectory), DirOpenFile);
}

//回收磁盘块
void deallocateDisk(const SInode &vInode, SBitMap &vioCBitMap) {
    int i = 0;
    while (i < vInode.NumBlocks) {
        if (vInode.BlockNums[i] != -1)
            clearBitAt(vInode.BlockNums[i], vioCBitMap);
        i++;
    }
}

void saveInode2Disk(const SInode &vInode, int vInodeNum) {
    memmove(g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * vInodeNum, &vInode, sizeof(SInode));
}

bool createFile(const char *vFileName, int vDirInodeNum, char FileType, int vFileSize) {
    if (vDirInodeNum >= g_NumInodes) return false;
    if (vFileSize > g_MaxFileSize) return false;

    SDirectory TempDirectory = loadDirectoryFromDisk(vDirInodeNum);

    bool IsSuccess = true;
    if (findFileInodeNum(vFileName, TempDirectory) != -1) {
        int fileindex = findFileIndex(vFileName, TempDirectory);
        short targetInodeNum = TempDirectory.FileSet[fileindex].InodeNum;
        SInode targetInode = loadInodeFromDisk(targetInodeNum);
        if (vFileSize == targetInode.FileSize || vFileSize == 0)//链接或同一文件
        {
            printf("creating %s links\n", vFileName);
            targetInode.NumLinks++;
            saveInode2Disk(targetInode, targetInodeNum);
            IsSuccess = true;
        } else {
            IsSuccess = false;//重名文件,不考虑覆盖
        }
    } else {
        SBitMap InodeBitMap{};
        createEmptyBitMap(InodeBitMap, g_NumInodes);
        memmove(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);            //从虚拟硬盘中读取Inode位示图

        int InodeIndex = findAndSetAvailableBit(InodeBitMap);//查找第一个可用的Inode
        if (InodeIndex == -1) IsSuccess = false;
        else if (!addFile2Directory(vFileName, InodeIndex, TempDirectory)) IsSuccess = false;
        else {
            SBitMap DataBlockBitMap{};
            createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
            memmove(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                      //从虚拟硬盘读取数据块位示图

            SInode TempInode{};
            if (!allocateDisk(TempInode, vFileSize, DataBlockBitMap)) IsSuccess = false;
            else {
                printf("Creating file %s(type:%c) size %d at %s\n", vFileName, FileType, vFileSize,
                       TempDirectory.FileName);
                TempInode.FileType = FileType;
                saveInode2Disk(TempInode, InodeIndex);                                       //将Inode信息写回虚拟硬盘
                memmove(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                 //将数据块位示图写回虚拟硬盘
                memmove(g_Disk + g_BlockBitMapSize, InodeBitMap.pMapData, g_InodeBitMapSize);   //将Inode位示图写回虚拟硬盘
                saveDirectory2Disk(vDirInodeNum, TempDirectory);
                if (FileType == 'd') {
                    SDirectory SubDir = createEmptyDirectory();
                    strncpy(SubDir.FileName, vFileName, g_MaxFileNameLen);
                    saveDirectory2Disk(InodeIndex, SubDir);
                }
            }
            delete DataBlockBitMap.pMapData;
        }
        delete InodeBitMap.pMapData;
    }
    return IsSuccess;
}

bool removeFile(const char *vFileName, int vDirInodeNum) {
    SDirectory sDirectory = loadDirectoryFromDisk(vDirInodeNum);
    short inodeNum = -1;
    SInode inode{};
    int i;
    while (i < g_MaxNumFiles) {
        if (strcmp(vFileName, sDirectory.FileSet[i].FileName) == 0) {
            inodeNum = sDirectory.FileSet[i].InodeNum;
            break;
        }
        i++;
    }
    if (inodeNum == -1) {
        return false;
    }
    inode = loadInodeFromDisk(inodeNum);
    if (inode.FileType == 'f')//如果是文件
    {
        if (inode.NumLinks > 1) {
            inode.NumLinks--;
        } else {
            SBitMap sBitMap{};
            SBitMap bitMap{};
            createEmptyBitMap(bitMap, g_NumInodes);
            memmove(bitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);
            createEmptyBitMap(sBitMap, g_NumBlocks);
            memmove(sBitMap.pMapData, g_Disk, g_BlockBitMapSize);
            deallocateDisk(inode, sBitMap);
            memmove(g_Disk, sBitMap.pMapData, g_BlockBitMapSize);
            clearBitAt(inodeNum, bitMap);
            memmove(g_Disk + g_BlockBitMapSize, bitMap.pMapData, g_InodeBitMapSize);
        }
    } else//如果是目录
    {
        SDirectory disk = loadDirectoryFromDisk(inodeNum);
        SBitMap InodeBitMap{};
        SBitMap DataBlockBitMap{};
        createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
        memmove(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);
        createEmptyBitMap(InodeBitMap, g_NumInodes);
        memmove(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);
        i = 0;
        while(i < g_MaxNumFiles)
        {
            if(disk.FileSet[i].IsInUse)
                removeFile(disk.FileSet[i].FileName, inodeNum);
            i++;
        }
        clearBitAt(inodeNum, InodeBitMap);
        deallocateDisk(inode, DataBlockBitMap);
        memmove(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);
        memmove(g_Disk + g_BlockBitMapSize, InodeBitMap.pMapData, g_InodeBitMapSize);
    }

    removeFileFromDirectory(vFileName, sDirectory);
    saveDirectory2Disk(vDirInodeNum, sDirectory);                          //写回目录内容
    return true;
}


void formatDisk() {
    memset(g_Disk, 0, g_DiskSize);

    SBitMap InodeDiskBitMap{};
    createEmptyBitMap(InodeDiskBitMap, g_NumInodes);                                   //创建Inode位示图
    markBitAt(0, InodeDiskBitMap);                                                     //为目录分配Inode，默认为第0个Inode
    memmove(g_Disk + g_BlockBitMapSize, InodeDiskBitMap.pMapData, g_InodeBitMapSize);     //将Inode位示图写回虚拟硬盘
    delete InodeDiskBitMap.pMapData;

    SBitMap DataBlockBitMap{};
    createEmptyBitMap(DataBlockBitMap, g_NumBlocks);                                   //创建数据块位示图

    SDirectory Directory = createEmptyDirectory();                                     //创建根目录
    strcpy(Directory.FileName, "/");
    SInode DirInode{};
    DirInode.FileType = 'd';
    allocateDisk(DirInode, sizeof(SDirectory), DataBlockBitMap);                       //分配根目录数据块

    memmove(g_Disk + g_BlockBitMapSize + g_InodeBitMapSize, &DirInode,
            sizeof(SInode)); //将目录Inode信息写回                               //将Inode信息写回虚拟硬盘
    memmove(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                       //将数据块位示图写回虚拟硬盘
    delete DataBlockBitMap.pMapData;

    saveDirectory2Disk(0, Directory);
}


SOpenFile *openFile(const char *vFileName)                  //假设输入的是完整路径，因此从根目录开始查找文件
{
    SDirectory TempDir = loadDirectoryFromDisk(0);          //读取根目录内容

    int FileInodeNum = -1;
    SInode FileInode{};
    char *pStr = new char[strlen(vFileName) + 1];
    strcpy(pStr, vFileName);
    char *pTemp = strtok(pStr, "/");                        //以'/'分割字符串
    while (pTemp != nullptr)                                   //按路径依次查找文件
    {
        FileInodeNum = findFileInodeNum(pTemp, TempDir);
        if (FileInodeNum == -1) return nullptr;
        else {
            FileInode = loadInodeFromDisk(FileInodeNum);
            if (FileInode.FileType == 'd') TempDir = loadDirectoryFromDisk(FileInodeNum);
        }
        pTemp = strtok(nullptr, "/");
    }
    delete[] pStr;
    if (FileInode.FileType == 'd') return nullptr;             //假如打开的是目录，返回NULL表示不能写入

    auto *pOpenFile = new SOpenFile();
    pOpenFile->CurSeekPos = 0;
    pOpenFile->InodeNum = FileInodeNum;
    pOpenFile->Inode = FileInode;
    return pOpenFile;
}

