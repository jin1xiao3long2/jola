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
    int CurSeekPos;                  //?��?????��??��??
    SInode Inode;
};

const int g_DiskSize = g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes + g_BlockSize * g_NumBlocks;
extern char g_Disk[g_DiskSize];


int readDataFromFile(void *vDestination, int vNumBytes, SOpenFile &vioFile) {
    int FileLength = vioFile.Inode.FileSize;
    if ((vNumBytes <= 0) || (vioFile.CurSeekPos >= FileLength)) return 0;   //��ȡ�����ļ�ĩβ
    if ((vioFile.CurSeekPos + vNumBytes) > FileLength) vNumBytes = FileLength - vioFile.CurSeekPos;//��Խ��

    int FirstBlock =
            vioFile.CurSeekPos / g_BlockSize;                      //������ʼ��ĩβ�����ݿ飬�������Ľ����ʾInode.BlockNums[]�����е��±귶Χ
    int LastBlock = (vioFile.CurSeekPos + vNumBytes - 1) / g_BlockSize;       //����curseekposָ���һ��
    int NumBlocks = 1 + LastBlock - FirstBlock;

    char *pDiskDataPos = g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes;//ָ���ڴ���ʼ
    char *pBuff = new char[NumBlocks * g_BlockSize];//������
    char *pTemp = pBuff;//��ֹ�ƶ�pBuffָ��
    for (int i = FirstBlock; i <= LastBlock; ++i)//�����ļ�ȫ������
    {
        memmove(pTemp, pDiskDataPos + g_BlockSize * vioFile.Inode.BlockNums[i], g_BlockSize);
        pTemp += g_BlockSize;
    }

    memmove(vDestination, &pBuff[vioFile.CurSeekPos % g_BlockSize], vNumBytes);//pBuffΪ�ַ�����
    delete[] pBuff;
    vioFile.CurSeekPos += vNumBytes;
    return vNumBytes;
}

int writefile(const SDirectory &sourece, int byte, SOpenFile &file) {
    if (byte <= 0)
        return 0;
    if (file.CurSeekPos + byte > g_MaxFileSize)            //������󳤶�
        byte = g_MaxFileSize - file.CurSeekPos;
    if (file.CurSeekPos + byte > file.Inode.FileSize) {  //���������С
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
        memmove(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);//д������Ӳ��
    }
    int block =
            file.CurSeekPos / g_BlockSize;
    int finalBlock = (file.CurSeekPos + byte - 1) / g_BlockSize;
    int numfBlocks = 1 + finalBlock - block;

    char *pos = g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes; //ָ����ʼλ��
    char *buff = new char[numfBlocks * g_BlockSize];
    char *temp = buff;
    int i = block;
    while (i <= finalBlock) { //��������
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
    //return g_RootDir;        //��������ȫ�ֱ�������Dir����ʵ�����ļ���д�������
    SOpenFile DirOpenFile{};
    DirOpenFile.CurSeekPos = 0;
    DirOpenFile.InodeNum = vDirInodeNum;
    DirOpenFile.Inode = loadInodeFromDisk(vDirInodeNum);     //����INode��ţ���ȡĿ¼��Inode��Ϣ
    assert(DirOpenFile.Inode.FileType == 'd');//�����䣬Ϊ������ִֹ��

    SDirectory TempDir{};
    readDataFromFile(&TempDir, sizeof(SDirectory), DirOpenFile);

    return TempDir;
}

bool allocateDisk(SInode &voInode, int vFileSize, SBitMap &vioBlockBitMap) {
    voInode.FileSize = vFileSize;
    voInode.NumLinks = 1;
    voInode.NumBlocks = (int) ceil(vFileSize / (double) g_BlockSize);//ceil������ȡ��

    if (countClearBits(vioBlockBitMap) < voInode.NumBlocks) return false;//ʣ��λ����������λ��

    for (int i = 0; i < voInode.NumBlocks; ++i)
        voInode.BlockNums[i] = findAndSetAvailableBit(vioBlockBitMap);//�������->�����һ��
    for (int i = voInode.NumBlocks; i < g_MaxNumBlock; ++i) voInode.BlockNums[i] = -1;//δ���õ��Ĳ�����-1

    return true;
}

void saveDirectory2Disk(int vDirInodeNum, const SDirectory &vDirectory) {
    //g_RootDir = vDirectory;   //����Ҳ����ȫ�ֵı�������Ŀ¼����ʵ�����ļ���д�������
    SOpenFile DirOpenFile{};
    DirOpenFile.CurSeekPos = 0;
    DirOpenFile.InodeNum = vDirInodeNum;
    DirOpenFile.Inode = loadInodeFromDisk(vDirInodeNum);     //����INode��ţ���ȡĿ¼��Inode��Ϣ
    assert(DirOpenFile.Inode.FileType == 'd');
    writefile(vDirectory, sizeof(SDirectory), DirOpenFile);
}

//���մ��̿�
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
        if (vFileSize == targetInode.FileSize || vFileSize == 0)//���ӻ�ͬһ�ļ�
        {
            printf("creating %s links\n", vFileName);
            targetInode.NumLinks++;
            saveInode2Disk(targetInode, targetInodeNum);
            IsSuccess = true;
        } else {
            IsSuccess = false;//�����ļ�,�����Ǹ���
        }
    } else {
        SBitMap InodeBitMap{};
        createEmptyBitMap(InodeBitMap, g_NumInodes);
        memmove(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);            //������Ӳ���ж�ȡInodeλʾͼ

        int InodeIndex = findAndSetAvailableBit(InodeBitMap);//���ҵ�һ�����õ�Inode
        if (InodeIndex == -1) IsSuccess = false;
        else if (!addFile2Directory(vFileName, InodeIndex, TempDirectory)) IsSuccess = false;
        else {
            SBitMap DataBlockBitMap{};
            createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
            memmove(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                      //������Ӳ�̶�ȡ���ݿ�λʾͼ

            SInode TempInode{};
            if (!allocateDisk(TempInode, vFileSize, DataBlockBitMap)) IsSuccess = false;
            else {
                printf("Creating file %s(type:%c) size %d at %s\n", vFileName, FileType, vFileSize,
                       TempDirectory.FileName);
                TempInode.FileType = FileType;
                saveInode2Disk(TempInode, InodeIndex);                                       //��Inode��Ϣд������Ӳ��
                memmove(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                 //�����ݿ�λʾͼд������Ӳ��
                memmove(g_Disk + g_BlockBitMapSize, InodeBitMap.pMapData, g_InodeBitMapSize);   //��Inodeλʾͼд������Ӳ��
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
    if (inode.FileType == 'f')//������ļ�
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
    } else//�����Ŀ¼
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
    saveDirectory2Disk(vDirInodeNum, sDirectory);                          //д��Ŀ¼����
    return true;
}


void formatDisk() {
    memset(g_Disk, 0, g_DiskSize);

    SBitMap InodeDiskBitMap{};
    createEmptyBitMap(InodeDiskBitMap, g_NumInodes);                                   //����Inodeλʾͼ
    markBitAt(0, InodeDiskBitMap);                                                     //ΪĿ¼����Inode��Ĭ��Ϊ��0��Inode
    memmove(g_Disk + g_BlockBitMapSize, InodeDiskBitMap.pMapData, g_InodeBitMapSize);     //��Inodeλʾͼд������Ӳ��
    delete InodeDiskBitMap.pMapData;

    SBitMap DataBlockBitMap{};
    createEmptyBitMap(DataBlockBitMap, g_NumBlocks);                                   //�������ݿ�λʾͼ

    SDirectory Directory = createEmptyDirectory();                                     //������Ŀ¼
    strcpy(Directory.FileName, "/");
    SInode DirInode{};
    DirInode.FileType = 'd';
    allocateDisk(DirInode, sizeof(SDirectory), DataBlockBitMap);                       //�����Ŀ¼���ݿ�

    memmove(g_Disk + g_BlockBitMapSize + g_InodeBitMapSize, &DirInode,
            sizeof(SInode)); //��Ŀ¼Inode��Ϣд��                               //��Inode��Ϣд������Ӳ��
    memmove(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                       //�����ݿ�λʾͼд������Ӳ��
    delete DataBlockBitMap.pMapData;

    saveDirectory2Disk(0, Directory);
}


SOpenFile *openFile(const char *vFileName)                  //���������������·������˴Ӹ�Ŀ¼��ʼ�����ļ�
{
    SDirectory TempDir = loadDirectoryFromDisk(0);          //��ȡ��Ŀ¼����

    int FileInodeNum = -1;
    SInode FileInode{};
    char *pStr = new char[strlen(vFileName) + 1];
    strcpy(pStr, vFileName);
    char *pTemp = strtok(pStr, "/");                        //��'/'�ָ��ַ���
    while (pTemp != nullptr)                                   //��·�����β����ļ�
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
    if (FileInode.FileType == 'd') return nullptr;             //����򿪵���Ŀ¼������NULL��ʾ����д��

    auto *pOpenFile = new SOpenFile();
    pOpenFile->CurSeekPos = 0;
    pOpenFile->InodeNum = FileInodeNum;
    pOpenFile->Inode = FileInode;
    return pOpenFile;
}

