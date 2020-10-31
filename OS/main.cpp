#include <memory.h>
#include <stdio.h>
#include "FileSystem.h"

void test()
{
	formatDisk();

	SBitMap InodeBitMap;
	createEmptyBitMap(InodeBitMap, g_NumInodes);

	SBitMap DataBlockBitMap;
	createEmptyBitMap(DataBlockBitMap, g_NumBlocks);

	memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);   //������Ӳ���ж�ȡInode��λʾͼ
	memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                 //������Ӳ�̶�ȡ���ݿ�λʾͼ

	printf("Inode usage:");
	printfBitMap(InodeBitMap);
	printf("Block usage:");
	printfBitMap(DataBlockBitMap);
	printf("\n");

	createFile("a.txt",  0, 'f', g_MaxFileSize);
	createFile("b.txt", 0, 'f', g_MaxFileSize);
	createFile("b.txt", 0, 'f', 0);

	memcpy(InodeBitMap.pMapData, g_Disk+g_BlockBitMapSize, g_InodeBitMapSize);   //������Ӳ���ж�ȡInode��λʾͼ
	memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                 //������Ӳ�̶�ȡ���ݿ�λʾͼ
	printf("Inode usage:");
	printfBitMap(InodeBitMap);
	printf("Block usage:");
	printfBitMap(DataBlockBitMap);

	removeFile("test.txt", 0);
	removeFile("test.txt", 0);
	memcpy(InodeBitMap.pMapData, g_Disk+g_BlockBitMapSize, g_InodeBitMapSize);   //������Ӳ���ж�ȡInode��λʾͼ
	memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                 //������Ӳ�̶�ȡ���ݿ�λʾͼ
	printf("\nInode usage:");
	printfBitMap(InodeBitMap);
	printf("Block usage:");
	printfBitMap(DataBlockBitMap);

/*	delete InodeBitMap.pMapData;
	delete DataBlockBitMap.pMapData;*/
}

void testForReadAndWriteFiles()
{
	createFile("test2.txt", 0, 'f', 128);
	SOpenFile DirOpenFile;
	DirOpenFile.CurSeekPos = 0;
	DirOpenFile.InodeNum = 1;
	DirOpenFile.Inode = loadInodeFromDisk(1);     //����INode��ţ���ȡĿ¼��Inode��Ϣ

	SBitMap InodeBitMap;
	createEmptyBitMap(InodeBitMap, g_NumInodes);

	SBitMap DataBlockBitMap;
	createEmptyBitMap(DataBlockBitMap, g_NumBlocks);

	memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);   //������Ӳ���ж�ȡInode��λʾͼ
	memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                 //������Ӳ�̶�ȡ���ݿ�λʾͼ

	printf("Inode usage:");
	printfBitMap(InodeBitMap);
	printf("Block usage:");
	printfBitMap(DataBlockBitMap);
	printf("\n");

	writeData2File("", 256, DirOpenFile);

	memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);   //������Ӳ���ж�ȡInode��λʾͼ
	memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);                 //������Ӳ�̶�ȡ���ݿ�λʾͼ

	printf("Inode usage:");
	printfBitMap(InodeBitMap);
	printf("Block usage:");
	printfBitMap(DataBlockBitMap);
	printf("\n");
}

int main(void)
{
	test();
	//testForReadAndWriteFiles();
	return 0;
} 