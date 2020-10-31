#pragma once

#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
const short g_MaxNumFiles = 10;
const short g_MaxFileNameLen = 10;

struct SDirectoryEntry               //Ŀ¼��
{
    bool IsInUse;
    short InodeNum;
    char FileName[g_MaxFileNameLen + 1];
};

struct SDirectory {
    char FileName[g_MaxFileNameLen + 1];
    SDirectoryEntry FileSet[g_MaxNumFiles];   //�ٶ�һ��Ŀ¼ֻ�ܴ洢g_MaxNumFiles���ļ�
};

//��Ŀ¼�����vFileName�ļ�,�ļ���Ӧ��INodeΪvInodeNum
bool addFile2Directory(const char *vFileName, short vInodeNum, SDirectory &voDirectory) {
    //Ѱ��Ŀ¼��
    int i;
    while(i < g_MaxNumFiles)
    {
        if(!voDirectory.FileSet[i].IsInUse) {
            strcpy_s(voDirectory.FileSet[i].FileName, vFileName);
            voDirectory.FileSet[i].InodeNum = vInodeNum;
            voDirectory.FileSet[i].IsInUse = true;
            return true;
        }
        i++;
    }
    return false;
}

//�����ļ���ΪvFileName���±꣬�������򷵻�-1
int findFileIndex(const char *vFileName, const SDirectory &vDirectory) {
    int i;
    while(i < g_MaxNumFiles)
    {
        if(!vDirectory.FileSet[i].IsInUse)
            continue;
        if(!strcmp(vFileName, vDirectory.FileSet[i].FileName))
            return i;
        i++;
    }
    if(i == g_MaxNumFiles)
        return -1;
    else
        std::cerr << "ERROR IN FINDING FILE INDEX!\n";
}
//����vFileName�ļ���INode���
int findFileInodeNum(const char *vFileName, const SDirectory &vDirectory) {
    int FileIndex = findFileIndex(vFileName, vDirectory);

    return (FileIndex != -1) ? vDirectory.FileSet[FileIndex].InodeNum : -1;
}

SDirectory createEmptyDirectory() {
    SDirectory Directory;
    memset(Directory.FileName, 0, g_MaxFileNameLen + 1);
    for (short i = 0; i < g_MaxNumFiles; ++i) {
        Directory.FileSet[i].InodeNum = -1;
        Directory.FileSet[i].IsInUse = false;
        memset(Directory.FileSet[i].FileName, 0, g_MaxFileNameLen + 1);
    }
    return Directory;
}
//��Ŀ¼���Ƴ�vFileName�ļ�
bool removeFileFromDirectory(const char *vFileName, SDirectory &vioDirectory) {
    int FileIndex = findFileIndex(vFileName, vioDirectory);

    if (FileIndex == -1) return false;

    vioDirectory.FileSet[FileIndex].InodeNum = -1;
    vioDirectory.FileSet[FileIndex].IsInUse = false;
    memset(vioDirectory.FileSet[FileIndex].FileName, 0, g_MaxFileNameLen + 1);
    return true;
}
