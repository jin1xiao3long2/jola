#include <memory.h>
#include <stdio.h>
#include <cstring>
#include "FileSystem.hpp"

char g_Disk[g_DiskSize];

void fun() {
    formatDisk();

    SBitMap InodeBitMap;
    createEmptyBitMap(InodeBitMap, g_NumInodes);

    SBitMap DataBlockBitMap;
    createEmptyBitMap(DataBlockBitMap, g_NumBlocks);

    memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);
    memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);

    display(InodeBitMap, true);
    display(DataBlockBitMap, false);
    printf("\n");

    createFile("a.txt", 0, 'f', g_MaxFileSize);
    createFile("b.txt", 0, 'f', g_MaxFileSize);
    createFile("b.txt", 0, 'f', 0);

    memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);
    memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);
    display(InodeBitMap, true);
    display(DataBlockBitMap, false);

    removeFile("a.txt", 0);
    removeFile("b.txt", 0);
    memcpy(InodeBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);
    memcpy(DataBlockBitMap.pMapData, g_Disk, g_BlockBitMapSize);
    display(InodeBitMap, true);
    display(DataBlockBitMap, false);

}

void testFileOperation() {
    createFile("mytest.txt", 0, 'f', 128);
    SOpenFile sOpenFile;
    sOpenFile.CurSeekPos = 0;
    sOpenFile.InodeNum = 1;
    sOpenFile.Inode = loadInodeFromDisk(1);
    SBitMap sBitMap, voBitMap;
    createEmptyBitMap(sBitMap, g_NumInodes);
    createEmptyBitMap(voBitMap, g_NumBlocks);
    memmove(sBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);
    memmove(voBitMap.pMapData, g_Disk, g_BlockBitMapSize);
    display(sBitMap, true);
    display(voBitMap, false);
    writefile(SDirectory(), 256, sOpenFile);
    memmove(sBitMap.pMapData, g_Disk + g_BlockBitMapSize, g_InodeBitMapSize);
    memmove(voBitMap.pMapData, g_Disk, g_BlockBitMapSize);
    display(sBitMap, true);
    display(voBitMap, false);
}

int main(void) {
    fun();
    //testFileOperation();
    return 0;
} 