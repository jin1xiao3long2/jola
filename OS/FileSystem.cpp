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
		if (vFileSize == targetInode.FileSize || vFileSize == 0)//���ӻ�ͬһ�ļ�
		{
			printf("creating %s links\n", vFileName);
			targetInode.NumLinks++;
			saveInode2Disk(targetInode, targetInodeNum);
			IsSuccess = true;
		}
		else
		{
			IsSuccess = false;//�����ļ�,�����Ǹ���
		}
	}
	else
	{	
		SBitMap InodeBitMap; 
		createEmptyBitMap(InodeBitMap, g_NumInodes);
		memcpy(InodeBitMap.pMapData, g_Disk+g_BlockBitMapSize, g_InodeBitMapSize);            //������Ӳ���ж�ȡInodeλʾͼ

		int InodeIndex = findAndSetAvailableBit(InodeBitMap);//���ҵ�һ�����õ�Inode
		if (InodeIndex == -1) IsSuccess = false;
		else if (!addFile2Directory(vFileName, InodeIndex, TempDirectory)) IsSuccess =  false;
		else 
		{
			SBitMap DataBlockBitMap;
			createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
			memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                      //������Ӳ�̶�ȡ���ݿ�λʾͼ

			SInode TempInode;
			if (!allocateDisk(TempInode, vFileSize, DataBlockBitMap)) IsSuccess =  false;	
			else 
			{
				printf("Creating file %s(type:%c) size %d at %s\n", vFileName, FileType, vFileSize, TempDirectory.FileName);
				TempInode.FileType = FileType;
				saveInode2Disk(TempInode, InodeIndex);                                       //��Inode��Ϣд������Ӳ��
				memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                 //�����ݿ�λʾͼд������Ӳ��
				memcpy(g_Disk+g_BlockBitMapSize, InodeBitMap.pMapData, g_InodeBitMapSize);   //��Inodeλʾͼд������Ӳ��
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
	//...       ��Ŀ¼���ҵ��ļ���Ӧ��Inode��ţ�����Inode��Ŷ���Inode���ݣ�����ļ���ɾ��
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
		return false;//�ļ������ڣ�ɾ��ʧ��
	}
	targetInode = loadInodeFromDisk(fileInodeNum);
	if (targetInode.FileType == 'f')//�ļ�
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
			memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);            //������Ӳ���ж�ȡInodeλʾͼ
			createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
			memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                      //������Ӳ�̶�ȡ���ݿ�λʾͼ
			deallocateDisk(targetInode, DataBlockBitMap);
			memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);//д��
			clearBitAt(fileInodeNum, InodeBitMap);
			memcpy(g_Disk + g_BlockBitMapSize, InodeBitMap.pMapData, g_InodeBitMapSize);
		}
	}
	else//Ŀ¼
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
	saveDirectory2Disk(vDirInodeNum, TempDirectory);                          //��Ŀ¼��������д������Ӳ��
	return true;
}

SDirectory loadDirectoryFromDisk(int vDirInodeNum)
{
	//return g_RootDir;        //��������ȫ�ֱ�������Dir����ʵ�����ļ���д�������
	SOpenFile DirOpenFile;
	DirOpenFile.CurSeekPos = 0;
	DirOpenFile.InodeNum = vDirInodeNum;
	DirOpenFile.Inode = loadInodeFromDisk(vDirInodeNum);     //����INode��ţ���ȡĿ¼��Inode��Ϣ
	assert(DirOpenFile.Inode.FileType == 'd');//�����䣬Ϊ������ִֹ��

	SDirectory TempDir;
	readDataFromFile(&TempDir, sizeof(SDirectory), DirOpenFile);

	return TempDir;
}

void saveDirectory2Disk(int vDirInodeNum, const SDirectory& vDirectory)
{
	//g_RootDir = vDirectory;   //����Ҳ����ȫ�ֵı�������Ŀ¼����ʵ�����ļ���д�������
	SOpenFile DirOpenFile;
	DirOpenFile.CurSeekPos = 0;
	DirOpenFile.InodeNum = vDirInodeNum;
	DirOpenFile.Inode = loadInodeFromDisk(vDirInodeNum);     //����INode��ţ���ȡĿ¼��Inode��Ϣ
	assert(DirOpenFile.Inode.FileType == 'd');

	writeData2File(&vDirectory, sizeof(SDirectory), DirOpenFile);
}

void formatDisk()
{
	memset(g_Disk, 0, g_DiskSize);

	SBitMap InodeDiskBitMap;
	createEmptyBitMap(InodeDiskBitMap, g_NumInodes);                                   //����Inodeλʾͼ
	markBitAt(0, InodeDiskBitMap);                                                     //ΪĿ¼����Inode��Ĭ��Ϊ��0��Inode
	memcpy(g_Disk+g_BlockBitMapSize, InodeDiskBitMap.pMapData, g_InodeBitMapSize);     //��Inodeλʾͼд������Ӳ��
	delete InodeDiskBitMap.pMapData;

	SBitMap DataBlockBitMap;
	createEmptyBitMap(DataBlockBitMap, g_NumBlocks);                                   //�������ݿ�λʾͼ

	SDirectory Directory = createEmptyDirectory();                                     //������Ŀ¼
	strcpy(Directory.FileName, "/");
	SInode DirInode;
	DirInode.FileType  = 'd';
	allocateDisk(DirInode, sizeof(SDirectory), DataBlockBitMap);                       //�����Ŀ¼���ݿ�
	
	memcpy(g_Disk + g_BlockBitMapSize + g_InodeBitMapSize, &DirInode, sizeof(SInode)); //��Ŀ¼Inode��Ϣд��                               //��Inode��Ϣд������Ӳ��
	memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                       //�����ݿ�λʾͼд������Ӳ��
	delete DataBlockBitMap.pMapData;

	saveDirectory2Disk(0, Directory);
}

bool allocateDisk(SInode& voInode, int vFileSize, SBitMap& vioBlockBitMap)
{
	voInode.FileSize  = vFileSize;
	voInode.NumLinks  = 1;
	voInode.NumBlocks = (int)ceil(vFileSize / (double)g_BlockSize);//ceil������ȡ��

	if (countClearBits(vioBlockBitMap) < voInode.NumBlocks) return false;//ʣ��λ����������λ��

	for (int i=0; i<voInode.NumBlocks; ++i) voInode.BlockNums[i] = findAndSetAvailableBit(vioBlockBitMap);//�������->�����һ��
	for (int i=voInode.NumBlocks; i<g_MaxNumBlock; ++i) voInode.BlockNums[i] = -1;//δ���õ��Ĳ�����-1
	
	return true;
}

void deallocateDisk(const SInode& vInode, SBitMap& vioCBitMap)
{
	//���մ��̿�
	for (int i = 0; i < vInode.NumBlocks; i++)
	{
		if (vInode.BlockNums[i] != -1)
			clearBitAt(vInode.BlockNums[i], vioCBitMap);//�޸�Ϊδ��ռ��
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

SOpenFile* openFile(const char* vFileName)                  //���������������·������˴Ӹ�Ŀ¼��ʼ�����ļ�
{
	SDirectory TempDir = loadDirectoryFromDisk(0);          //��ȡ��Ŀ¼����

	int FileInodeNum = -1;
	SInode FileInode;
	char *pStr = new char[strlen(vFileName) + 1];
	strcpy(pStr, vFileName);
	char *pTemp = strtok(pStr, "/");                        //��'/'�ָ��ַ���
	while (pTemp != NULL)                                   //��·�����β����ļ�
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
	if (FileInode.FileType == 'd') return NULL;             //����򿪵���Ŀ¼������NULL��ʾ����д��

	SOpenFile *pOpenFile = new SOpenFile();
	pOpenFile->CurSeekPos = 0;
	pOpenFile->InodeNum = FileInodeNum;
	pOpenFile->Inode = FileInode;
	return pOpenFile;
}

int readDataFromFile(void *vDestination, int vNumBytes, SOpenFile& vioFile)
{
	int FileLength = vioFile.Inode.FileSize;
	if ((vNumBytes <= 0) || (vioFile.CurSeekPos >= FileLength)) return 0;   //��ȡ�����ļ�ĩβ
	if ((vioFile.CurSeekPos + vNumBytes) > FileLength) vNumBytes = FileLength - vioFile.CurSeekPos;//��Խ��

	int FirstBlock = vioFile.CurSeekPos / g_BlockSize;                      //������ʼ��ĩβ�����ݿ飬�������Ľ����ʾInode.BlockNums[]�����е��±귶Χ
	int LastBlock = (vioFile.CurSeekPos + vNumBytes - 1) / g_BlockSize;	   //����curseekposָ���һ��
	int NumBlocks = 1 + LastBlock - FirstBlock;

	char *pDiskDataPos = g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes;//ָ���ڴ���ʼ
	char *pBuff = new char[NumBlocks * g_BlockSize];//������
	char *pTemp = pBuff;//��ֹ�ƶ�pBuffָ��
	for (int i = FirstBlock; i <= LastBlock; ++i)//�����ļ�ȫ������
	{
		memcpy(pTemp, pDiskDataPos + g_BlockSize * vioFile.Inode.BlockNums[i], g_BlockSize);
		pTemp += g_BlockSize;
	}

	memcpy(vDestination, &pBuff[vioFile.CurSeekPos % g_BlockSize], vNumBytes);//pBuffΪ�ַ�����
	delete[] pBuff;
	vioFile.CurSeekPos += vNumBytes;
	return vNumBytes;
}

int writeData2File(const void *vSrc, int vNumBytes, SOpenFile& vioFile)
{
	if (vNumBytes <= 0) return 0;

	if (vioFile.CurSeekPos + vNumBytes > g_MaxFileSize) vNumBytes = g_MaxFileSize - vioFile.CurSeekPos;  //����������ļ�����
	if (vioFile.CurSeekPos + vNumBytes > vioFile.Inode.FileSize)   //���д�����ݳ������ļ�ԭʼ����Ĵ�С����ô�죿
	{
		SBitMap DataBlockBitMap;
		createEmptyBitMap(DataBlockBitMap, g_NumBlocks);
		memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize); //��ȡ���ݿ�λʾͼ
		int reallocateBlockNums = (vioFile.CurSeekPos + vNumBytes - vioFile.Inode.FileSize) / g_BlockSize;
		for (int j = 0; j < reallocateBlockNums; j++)
		{
			vioFile.Inode.BlockNums[vioFile.Inode.NumBlocks] = findAndSetAvailableBit(DataBlockBitMap);
			vioFile.Inode.NumBlocks++;
		}
		memcpy(g_Disk, DataBlockBitMap.pMapData, g_BlockBitMapSize);                 //�����ݿ�λʾͼд������Ӳ��
		//�ȷ��������̿ռ䣬��û���򷵻ش���
		//����ռ����������Inode��Ϊ���������д������δ���������Сʱͬ������
	}


	int FirstBlock = vioFile.CurSeekPos / g_BlockSize;                      //������ʼ��ĩβ�����ݿ飬�������Ľ����ʾInode.BlockNums[]�����е��±귶Χ
	int LastBlock = (vioFile.CurSeekPos + vNumBytes - 1) / g_BlockSize;	   //����curseekposָ���һ��
	int NumBlocks = 1 + LastBlock - FirstBlock;

	char *pDiskDataPos = g_Disk + g_BlockBitMapSize + g_InodeBitMapSize + sizeof(SInode) * g_NumInodes;//ָ���ڴ���ʼ
	char *pBuff = new char[NumBlocks * g_BlockSize];//������
	char *pTemp = pBuff;//��ֹ�ƶ�pBuffָ��
	for (int i = FirstBlock; i <= LastBlock; ++i)//�����ļ�ȫ������
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

	//����ļ���д��
	//...
	//...
}