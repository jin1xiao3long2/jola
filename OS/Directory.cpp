#include "Directory.h"
#include <memory.h>
#include <string.h>
#include <stdio.h>

SDirectory createEmptyDirectory()
{
	SDirectory Directory;
	memset(Directory.FileName, 0, g_MaxFileNameLen+1);
	for (short i=0; i<g_MaxNumFiles; ++i)
	{
		Directory.FileSet[i].InodeNum = -1;
		Directory.FileSet[i].IsInUse = false;
		memset(Directory.FileSet[i].FileName, 0, g_MaxFileNameLen+1);
	}
	return Directory;
}

int findFileInodeNum(const char* vFileName, const SDirectory& vDirectory)
{
	int FileIndex = findFileIndex(vFileName, vDirectory);

	return (FileIndex != -1) ? vDirectory.FileSet[FileIndex].InodeNum : -1;
}

int findFileIndex(const char* vFileName, const SDirectory& vDirectory)
{
	int i;
	bool Isthesame = false;
	for (i = 0; i < g_MaxNumFiles; i++)
	{
		if (vDirectory.FileSet[i].IsInUse == false)
		{
			continue;
		}
		if (strcmp(vFileName, vDirectory.FileSet[i].FileName) == 0)
		{
			return i;
		}
	}
	if (i == g_MaxNumFiles)
	{
		return -1;
	}
	else
	{
		printf("FIND FILE INDEX ERROR\n");
		return 0;
	}
}

bool addFile2Directory(const char* vFileName, short vInodeNum, SDirectory& voDirectory)
{
	//遍历目录项数组，寻找可用的目录项
	int i;
	for (i = 0; i < g_MaxNumFiles; i++)
	{
		if (voDirectory.FileSet[i].IsInUse == false)
		{
			strcpy_s(voDirectory.FileSet[i].FileName, vFileName);
			voDirectory.FileSet[i].InodeNum = vInodeNum;
			voDirectory.FileSet[i].IsInUse = true;
			return true;
		}
	}
	return false;
}

bool removeFileFromDirectory(const char *vFileName, SDirectory& vioDirectory)
{ 
	int FileIndex = findFileIndex(vFileName, vioDirectory);

	if (FileIndex == -1) return false;

	vioDirectory.FileSet[FileIndex].InodeNum = -1;
	vioDirectory.FileSet[FileIndex].IsInUse = false;
	memset(vioDirectory.FileSet[FileIndex].FileName, 0, g_MaxFileNameLen+1);
	return true;
}