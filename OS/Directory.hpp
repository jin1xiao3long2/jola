#pragma once

#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
const short g_MaxNumFiles = 10;
const short g_MaxFileNameLen = 10;

struct SDirectoryEntry               //目录项
{
    bool IsInUse;
    short InodeNum;
    char FileName[g_MaxFileNameLen + 1];
};

struct SDirectory {
    char FileName[g_MaxFileNameLen + 1];
    SDirectoryEntry FileSet[g_MaxNumFiles];   //假定一个目录只能存储g_MaxNumFiles个文件
};

//在目录中添加vFileName文件,文件对应的INode为vInodeNum
bool addFile2Directory(const char *vFileName, short vInodeNum, SDirectory &voDirectory) {
    //寻找目录项
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

//查找文件名为vFileName的下标，不存在则返回-1
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
//查找vFileName文件的INode编号
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
//从目录中移除vFileName文件
bool removeFileFromDirectory(const char *vFileName, SDirectory &vioDirectory) {
    int FileIndex = findFileIndex(vFileName, vioDirectory);

    if (FileIndex == -1) return false;

    vioDirectory.FileSet[FileIndex].InodeNum = -1;
    vioDirectory.FileSet[FileIndex].IsInUse = false;
    memset(vioDirectory.FileSet[FileIndex].FileName, 0, g_MaxFileNameLen + 1);
    return true;
}
