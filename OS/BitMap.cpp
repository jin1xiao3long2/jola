#include "BitMap.h"
#include <math.h>
#include <stdio.h>

void createEmptyBitMap(SBitMap& voBitMap, int vNumTotalBits)
{
	voBitMap.NumBits  = vNumTotalBits;
	int NumWords = (int)ceil(vNumTotalBits / (double)g_NumBitsInWord);
	voBitMap.pMapData = new int[NumWords];

	for (int i=0; i<NumWords; ++i) voBitMap.pMapData[i] = 0;//0=δռ��
}

void markBitAt(int vBitPosition, SBitMap& vioBitMap) 
{ 
	vioBitMap.pMapData[vBitPosition / g_NumBitsInWord] |= 1 << (vBitPosition % g_NumBitsInWord);//word�е�ָ��λ��1��һ��������numbitsinword��λ
}

void clearBitAt(int vBitPosition, SBitMap& vioBitMap) 
{
	vioBitMap.pMapData[vBitPosition / g_NumBitsInWord] &= ~(1 << (vBitPosition % g_NumBitsInWord));//ȡ��ʹ�ó���ָ��λȫ������1
}

bool isAvailableBitAt(int vBitPosition, const SBitMap& vBitMap)
{
	int a = 0;
	a |= (1 << (vBitPosition % g_NumBitsInWord));//ȡ���ض�λ
	a &= vBitMap.pMapData[vBitPosition / g_NumBitsInWord];
	if (a == 0)//��λΪ0������
	{
		return true;
	}
	else//Ϊ1��������
	{
		return false;
	}
}

int countClearBits(const SBitMap& vBitMap)
{
	int i = 0, totalNum = 0;
	for (i = 0; i < vBitMap.NumBits; i++)
	{
		if (isAvailableBitAt(i, vBitMap) == true)
		{
			totalNum++;
		}
	}
	return totalNum;
}

int findAndSetAvailableBit(SBitMap& voBitMap) 
{
	int i;
	for (i = 0; i < voBitMap.NumBits; i++)
	{
		if (isAvailableBitAt(i, voBitMap) == true)
		{
			markBitAt(i, voBitMap);
			return i;
		}
	}
	return -1;
}

void printfBitMap(const SBitMap& vBitMap)
{
	for (int i=0; i<vBitMap.NumBits; ++i) 
	{
		if (isAvailableBitAt(i, vBitMap)) printf("0 ");
		else printf("1 "); 
	}
	printf("\n"); 
}