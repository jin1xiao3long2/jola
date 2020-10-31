#pragma once

#include <math.h>
#include <stdio.h>

const short g_NumBitsInWord = sizeof(int) * 8;

struct SBitMap {
    int NumBits;   //位示图大小
    int *pMapData;
};

//测试第vBitPosition位是否为0
bool isAvailableBitAt(int vBitPosition, const SBitMap &vBitMap) {
    int bit = 0;
    bit |= (1 << (vBitPosition % g_NumBitsInWord));
    bit &= vBitMap.pMapData[vBitPosition / g_NumBitsInWord];
    if (!bit) {
        return true;
    } else {
        return false;
    }
}

//统计vBitMap没有被占用的位数（为1表示占用，0表示没占用）
int countClearBits(const SBitMap &vBitMap) {
    int i = 0, num = 0;
    while (i < vBitMap.NumBits) {
        if (isAvailableBitAt(i, vBitMap))
            num++;
        i++;
    }
    return num;
}

//将位示图中第vBitPosition位置为1
void markBitAt(int vBitPosition, SBitMap &vioBitMap) {
    vioBitMap.pMapData[vBitPosition / g_NumBitsInWord] |=
            1 << (vBitPosition % g_NumBitsInWord);//word中的指定位置1，一个字中有numbitsinword个位
}

//返回第一个没有被占用的位，并将其置1;没有则返回-1
int findAndSetAvailableBit(SBitMap &voBitMap) {
    int i;
    while (i < voBitMap.NumBits) {
        if (isAvailableBitAt(i, voBitMap)) {
            markBitAt(i, voBitMap);
            return i;
        }
        i++;
    }
    return -1;
}



//创建一个大小为vNumTotalBits的空位示图

void createEmptyBitMap(SBitMap &voBitMap, int vNumTotalBits) {
    voBitMap.NumBits = vNumTotalBits;
    int NumWords = (int) ceil(vNumTotalBits / (double) g_NumBitsInWord);
    voBitMap.pMapData = new int[NumWords];

    for (int i = 0; i < NumWords; ++i) voBitMap.pMapData[i] = 0;//0=未占用
}


//将位示图中第vBitPosition位置为0
void clearBitAt(int vBitPosition, SBitMap &vioBitMap) {
    auto change = ~(1 << (vBitPosition % g_NumBitsInWord));
    vioBitMap.pMapData[vBitPosition / g_NumBitsInWord] &= change;
}

void display(const SBitMap &vBitMap, bool state) {
    if (state)
        printf("Inode:");
    else
        printf("Block:");
    for (int i = 0; i < vBitMap.NumBits; ++i) {
        if (isAvailableBitAt(i, vBitMap)) printf("0 ");
        else printf("1 ");
    }
    printf("\n");
}

