#include "BitMap.h"
#include <math.h>
#include <stdio.h>

void createEmptyBitMap(SBitMap& voBitMap, int vNumTotalBits)
{
	voBitMap.NumBits  = vNumTotalBits;
	int NumWords = (int)ceil(vNumTotalBits / (double)g_NumBitsInWord);
	voBitMap.pMapData = new int[NumWords];

	for (int i=0; i<NumWords; ++i) voBitMap.pMapData[i] = 0;//0=未占用
}

void markBitAt(int vBitPosition, SBitMap& vioBitMap) 
{ 
	vioBitMap.pMapData[vBitPosition / g_NumBitsInWord] |= 1 << (vBitPosition % g_NumBitsInWord);//word中的指定位置1，一个字中有numbitsinword个位
}

void clearBitAt(int vBitPosition, SBitMap& vioBitMap) 
{
	vioBitMap.pMapData[vBitPosition / g_NumBitsInWord] &= ~(1 << (vBitPosition % g_NumBitsInWord));//取反使得除了指定位全部被置1
}

bool isAvailableBitAt(int vBitPosition, const SBitMap& vBitMap)
{
	int a = 0;
	a |= (1 << (vBitPosition % g_NumBitsInWord));//取出特定位
	a &= vBitMap.pMapData[vBitPosition / g_NumBitsInWord];
	if (a == 0)//该位为0，可用
	{
		return true;
	}
	else//为1，不可用
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