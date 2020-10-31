#pragma once

#include <math.h>
#include <stdio.h>

const short g_NumBitsInWord = sizeof(int) * 8;

struct SBitMap {
    int NumBits;   //λʾͼ��С
    int *pMapData;
};

//���Ե�vBitPositionλ�Ƿ�Ϊ0
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

//ͳ��vBitMapû�б�ռ�õ�λ����Ϊ1��ʾռ�ã�0��ʾûռ�ã�
int countClearBits(const SBitMap &vBitMap) {
    int i = 0, num = 0;
    while (i < vBitMap.NumBits) {
        if (isAvailableBitAt(i, vBitMap))
            num++;
        i++;
    }
    return num;
}

//��λʾͼ�е�vBitPositionλ��Ϊ1
void markBitAt(int vBitPosition, SBitMap &vioBitMap) {
    vioBitMap.pMapData[vBitPosition / g_NumBitsInWord] |=
            1 << (vBitPosition % g_NumBitsInWord);//word�е�ָ��λ��1��һ��������numbitsinword��λ
}

//���ص�һ��û�б�ռ�õ�λ����������1;û���򷵻�-1
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



//����һ����СΪvNumTotalBits�Ŀ�λʾͼ

void createEmptyBitMap(SBitMap &voBitMap, int vNumTotalBits) {
    voBitMap.NumBits = vNumTotalBits;
    int NumWords = (int) ceil(vNumTotalBits / (double) g_NumBitsInWord);
    voBitMap.pMapData = new int[NumWords];

    for (int i = 0; i < NumWords; ++i) voBitMap.pMapData[i] = 0;//0=δռ��
}


//��λʾͼ�е�vBitPositionλ��Ϊ0
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

