#include "FileSystem.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

char g_Disk[g_DiskSize] = {'\0'};
SDirectory g_RootDir = createEmptyDirectory();

bool createFile(const char* vFileName, int vDirInodeNum, char FileType, int vFileSize)
{
	if (vDirInodeNum >= g_NumInodes) return false;
	if (vFileSize > g_MaxFileSize) return false;

	SDirectory TempDirectory = loadDirectoryFromDisk(vDirInodeNum);

	bool IsSuccess = true;
	if (findFileInodeNum(vFileName, TempDirectory) != -1)
	{
		int fileindex = findFileIndex(vFileName, TempDirectory);
		short targetInodeNum = TempDirectory.FileSet[fileindex].InodeNum;
		SInode targetInode = loadInodeFromDisk(targetInodeNum);
		if (vFileSize == targetInode.FileSize || vFileSize == 0)//链接或同一文件
		{
			printf("creating %s links\n", vFileName);
			targetInode.NumLinks++;
			saveInode2Disk(targetInode, targetInodeNum);
			IsSuccess = true;
		}
		else
		{
			IsSuccess = false;//重名文件,不考虑覆盖
		}
	}
	else
	{	
		SBitMap InodeBitMap; 
		createEmptyBitMap(InodeBitMap, g_NumInodes);
		memcpy(InodeBitMap.pMapData, g_Disk+g_BlockBitMapSize, g_InodeBitMapSize);            //从虚拟硬盘中读取Inode位示图

		int InodeIndex = findAndSetAvailableBit(InodeBitMap);//查找第一个可用的Inode
		if (InodeIndex == -1) IsSuccess = false;
		else if (!addFile2Directory(vFileName, InodeIndex, TempDirectory)) IsSuccess =  false;
		else 
		{
			SBitMap DataBlockBitMap;
			createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
			memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                      //从虚拟硬盘读取数据块位示图

			SInode TempInode;
			if (!allocateDisk(TempInode, vFileSize, DataBlockBitMap)) IsSuccess =  false;	
			else 
			{
				printf("Creating file %s(type:%c) size %d at %s\n", vFileName, FileType, vFileSize, TempDirectory.FileName);
				TempInode.FileType = FileType;
				saveInode2Disk(TempInode, InodeIndex);                                       //将Inode信息写回虚拟硬盘
				memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                 //将数据块位示图写回虚拟硬盘
				memcpy(g_Disk+g_BlockBitMapSize, InodeBitMap.pMapData, g_InodeBitMapSize);   //将Inode位示图写回虚拟硬盘
				saveDirectory2Disk(vDirInodeNum, TempDirectory);
				if (FileType == 'd')
				{
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

bool removeFile(const char* vFileName, int vDirInodeNum)
{
	SDirectory TempDirectory = loadDirectoryFromDisk(vDirInodeNum);
	int i;
	short fileInodeNum = -1;
	SInode targetInode;
	//...       从目录中找到文件对应的Inode编号，根据Inode编号读出Inode数据，完成文件的删除
	for (i = 0; i < g_MaxNumFiles; i++)
	{
		if (strcmp(vFileName, TempDirectory.FileSet[i].FileName) == 0)
		{
			fileInodeNum = TempDirectory.FileSet[i].InodeNum;
			break;
		}
	}
	if (fileInodeNum == -1)
	{
		return false;//文件不存在，删除失败
	}
	targetInode = loadInodeFromDisk(fileInodeNum);
	if (targetInode.FileType == 'f')//文件
	{
		if (targetInode.NumLinks > 1)
		{
			targetInode.NumLinks--;
		}
		else
		{
			SBitMap DataBlockBitMap;
			SBitMap InodeBitMap;
			createEmptyBitMap(InodeBitMap, g_NumInodes);
			memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);            //从虚拟硬盘中读取Inode位示图
			createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
			memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                      //从虚拟硬盘读取数据块位示图
			deallocateDisk(targetInode, DataBlockBitMap);
			memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);//写回
			clearBitAt(fileInodeNum, InodeBitMap);
			memcpy(g_Disk + g_BlockBitMapSize, InodeBitMap.pMapData, g_InodeBitMapSize);
		}
	}
	else//目录
	{
		SDirectory targerDir = loadDirectoryFromDisk(fileInodeNum);
		int j;
		SBitMap InodeBitMap;
		SBitMap DataBlockBitMap;
		createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
		memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);
		createEmptyBitMap(InodeBitMap, g_NumInodes);
		memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);
		for (j = 0; j < g_MaxNumFiles; j++)
		{
			if (targerDir.FileSet[j].IsInUse == true)
			{
				removeFile(targerDir.FileSet[j].FileName, fileInodeNum);
			}
		}
		clearBitAt(fileInodeNum, InodeBitMap);
		deallocateDisk(targetInode, DataBlockBitMap);
		memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);
		memcpy(g_Disk + g_BlockBitMapSize, InodeBitMap.pMapData, g_InodeBitMapSize);
	}
	
	removeFileFromDirectory(vFileName, TempDirectory);
	saveDirectory2Disk(vDirInodeNum, TempDirectory);                          //将目录内容重新写回虚拟硬盘
	return true;
}

SDirectory loadDirectoryFromDisk(int vDirInodeNum)
{
	//return g_RootDir;        //这里先用全局变量保存Dir，等实现了文件读写再来完成
	SOpenFile DirOpenFile;
	DirOpenFile.CurSeekPos = 0;
	DirOpenFile.InodeNum = vDirInodeNum;
	DirOpenFile.Inode = loadInodeFromDisk(vDirInodeNum);     //根据INode编号，读取目录的Inode信息
	assert(DirOpenFile.Inode.FileType == 'd');//检察语句，为假则中止执行

	SDirectory TempDir;
	readDataFromFile(&TempDir, sizeof(SDirectory), DirOpenFile);

	return TempDir;
}

void saveDirectory2Disk(int vDirInodeNum, const SDirectory& vDirectory)
{
	//g_RootDir = vDirectory;   //这里也是用全局的变量保存目录，等实现了文件读写再来完成
	SOpenFile DirOpenFile;
	DirOpenFile.CurSeekPos = 0;
	DirOpenFile.InodeNum = vDirInodeNum;
	DirOpenFile.Inode = loadInodeFromDisk(vDirInodeNum);     //根据INode编号，读取目录的Inode信息
	assert(DirOpenFile.Inode.FileType == 'd');

	writeData2File(&vDirectory, sizeof(SDirectory), DirOpenFile);
}

void formatDisk()
{
	memset(g_Disk, 0, g_DiskSize);

	SBitMap InodeDiskBitMap;
	createEmptyBitMap(InodeDiskBitMap, g_NumInodes);                                   //创建Inode位示图
	markBitAt(0, InodeDiskBitMap);                                                     //为目录分配Inode，默认为第0个Inode
	memcpy(g_Disk+g_BlockBitMapSize, InodeDiskBitMap.pMapData, g_InodeBitMapSize);     //将Inode位示图写回虚拟硬盘
	delete InodeDiskBitMap.pMapData;

	SBitMap DataBlockBitMap;
	createEmptyBitMap(DataBlockBitMap, g_NumBlocks);                                   //创建数据块位示图

	SDirectory Directory = createEmptyDirectory();                                     //创建根目录
	strcpy(Directory.FileName, "/");
	SInode DirInode;
	DirInode.FileType  = 'd';
	allocateDisk(DirInode, sizeof(SDirectory), DataBlockBitMap);                       //分配根目录数据块
	
	memcpy(g_Disk + g_BlockBitMapSize + g_InodeBitMapSize, &DirInode, sizeof(SInode)); //将目录Inode信息写回                               //将Inode信息写回虚拟硬盘
	memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                       //将数据块位示图写回虚拟硬盘
	delete DataBlockBitMap.pMapData;

	saveDirectory2Disk(0, Directory);
}

bool allocateDisk(SInode& voInode, int vFileSize, SBitMap& vioBlockBitMap)
{
	voInode.FileSize  = vFileSize;
	voInode.NumLinks  = 1;
	voInode.NumBlocks = (int)ceil(vFileSize / (double)g_BlockSize);//ceil：向上取整

	if (countClearBits(vioBlockBitMap) < voInode.NumBlocks) return false;//剩余位数少于请求位数

	for (int i=0; i<voInode.NumBlocks; ++i) voInode.BlockNums[i] = findAndSetAvailableBit(vioBlockBitMap);//随机分配->最近的一个
	for (int i=voInode.NumBlocks; i<g_MaxNumBlock; ++i) voInode.BlockNums[i] = -1;//未被用到的部分置-1
	
	return true;
}

void deallocateDisk(const SInode& vInode, SBitMap& vioCBitMap)
{
	//回收磁盘块
	for (int i = 0; i < vInode.NumBlocks; i++)
	{
		if (vInode.BlockNums[i] != -1)
			clearBitAt(vInode.BlockNums[i], vioCBitMap);//修改为未被占用
	}
}

SInode loadInodeFromDisk(int vInodeNum)
{
	SInode DirInode;
	memcpy(&DirInode, g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode)*vInodeNum, sizeof(SInode)); 

	return DirInode;
}

void saveInode2Disk(const SInode& vInode, int vInodeNum)
{
	memcpy(g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode)*vInodeNum, &vInode, sizeof(SInode)); 
}

SOpenFile* openFile(const char* vFileName)                  //假设输入的是完整路径，因此从根目录开始查找文件
{
	SDirectory TempDir = loadDirectoryFromDisk(0);          //读取根目录内容

	int FileInodeNum = -1;
	SInode FileInode;
	char *pStr = new char[strlen(vFileName) + 1];
	strcpy(pStr, vFileName);
	char *pTemp = strtok(pStr, "/");                        //以'/'分割字符串
	while (pTemp != NULL)                                   //按路径依次查找文件
	{
		FileInodeNum = findFileInodeNum(pTemp, TempDir);
		if (FileInodeNum == -1) return NULL;
		else
		{
			FileInode = loadInodeFromDisk(FileInodeNum);
			if (FileInode.FileType == 'd') TempDir = loadDirectoryFromDisk(FileInodeNum);
		}
		pTemp = strtok(NULL, "/");
	}
	delete[] pStr;
	if (FileInode.FileType == 'd') return NULL;             //假如打开的是目录，返回NULL表示不能写入

	SOpenFile *pOpenFile = new SOpenFile();
	pOpenFile->CurSeekPos = 0;
	pOpenFile->InodeNum = FileInodeNum;
	pOpenFile->Inode = FileInode;
	return pOpenFile;
}

int readDataFromFile(void *vDestination, int vNumBytes, SOpenFile& vioFile)
{
	int FileLength = vioFile.Inode.FileSize;
	if ((vNumBytes <= 0) || (vioFile.CurSeekPos >= FileLength)) return 0;   //读取到了文件末尾
	if ((vioFile.CurSeekPos + vNumBytes) > FileLength) vNumBytes = FileLength - vioFile.CurSeekPos;//防越界

	int FirstBlock = vioFile.CurSeekPos / g_BlockSize;                      //计算起始和末尾的数据块，这里计算的结果表示Inode.BlockNums[]数组中的下标范围
	int LastBlock = (vioFile.CurSeekPos + vNumBytes - 1) / g_BlockSize;	   //包含curseekpos指向的一块
	int NumBlocks = 1 + LastBlock - FirstBlock;

	char *pDiskDataPos = g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes;//指向内存起始
	char *pBuff = new char[NumBlocks * g_BlockSize];//缓冲区
	char *pTemp = pBuff;//防止移动pBuff指针
	for (int i = FirstBlock; i <= LastBlock; ++i)//读出文件全部内容
	{
		memcpy(pTemp, pDiskDataPos + g_BlockSize * vioFile.Inode.BlockNums[i], g_BlockSize);
		pTemp += g_BlockSize;
	}

	memcpy(vDestination, &pBuff[vioFile.CurSeekPos % g_BlockSize], vNumBytes);//pBuff为字符数组
	delete[] pBuff;
	vioFile.CurSeekPos += vNumBytes;
	return vNumBytes;
}

int writeData2File(const void *vSrc, int vNumBytes, SOpenFile& vioFile)
{
	if (vNumBytes <= 0) return 0;

	if (vioFile.CurSeekPos + vNumBytes > g_MaxFileSize) vNumBytes = g_MaxFileSize - vioFile.CurSeekPos;  //超过了最大文件长度
	if (vioFile.CurSeekPos + vNumBytes > vioFile.Inode.FileSize)   //如果写入内容超过了文件原始分配的大小，怎么办？
	{
		SBitMap DataBlockBitMap;
		createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
		memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize); //获取数据块位示图
		int reallocateBlockNums = (vioFile.CurSeekPos + vNumBytes - vioFile.Inode.FileSize) / g_BlockSize;
		for (int j = 0; j < reallocateBlockNums; j++)
		{
			vioFile.Inode.BlockNums[vioFile.Inode.NumBlocks] = findAndSetAvailableBit(DataBlockBitMap);
			vioFile.Inode.NumBlocks++;
		}
		memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                 //将数据块位示图写回虚拟硬盘
		//先分配多余磁盘空间，若没有则返回错误
		//分配空间后，以扩充后的Inode作为对象进行与写入内容未超过分配大小时同样处理
	}


	int FirstBlock = vioFile.CurSeekPos / g_BlockSize;                      //计算起始和末尾的数据块，这里计算的结果表示Inode.BlockNums[]数组中的下标范围
	int LastBlock = (vioFile.CurSeekPos + vNumBytes - 1) / g_BlockSize;	   //包含curseekpos指向的一块
	int NumBlocks = 1 + LastBlock - FirstBlock;

	char *pDiskDataPos = g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes;//指向内存起始
	char *pBuff = new char[NumBlocks * g_BlockSize];//缓冲区
	char *pTemp = pBuff;//防止移动pBuff指针
	for (int i = FirstBlock; i <= LastBlock; ++i)//读出文件全部内容
	{
		memcpy(pTemp, pDiskDataPos + g_BlockSize * vioFile.Inode.BlockNums[i], g_BlockSize);
		pTemp += g_BlockSize;
	}
	memcpy(pBuff, (char*)vSrc, vNumBytes);
	pTemp = pBuff;
	for (int i = FirstBlock; i <= LastBlock; i++)
	{
		memcpy(pDiskDataPos + g_BlockSize * vioFile.Inode.BlockNums[i], pTemp, g_BlockSize);
		pTemp += g_BlockSize;
	}
	vioFile.CurSeekPos += vNumBytes;
	delete[]pBuff;
	return vNumBytes;

	//完成文件的写入
	//...
	//...
}