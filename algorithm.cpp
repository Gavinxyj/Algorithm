#include<iostream>
#include "algorithm.h"


template<class T>
Algorithm<T>::Algorithm()
{
	
}

template<class T>
Algorithm<T>::~Algorithm()
{
	
}

template<class T>
void Algorithm<T>::bubbleSort(T *array, std::size_t nLen, int (*fCompare)(const T *, const T *))
{
		if(0 == *array || 0 == nLen) return;
		
		bool bFlag = true; //这里考虑如果待排序列是有序的则直接退出循环
		for(int nLoop = 0; nLoop < nLen -1; nLoop ++)
		{		
			
			for(int index = 0; index < nLen - 1 - nLoop; index ++)
			{
					if(fCompare(&array[index], &array[index + 1]) > 0)
					{
						T temp = array[index];
						array[index] = array[index + 1];
						array[index + 1]  = temp;	
						bFlag = false;
					}
			}	
		
			if(bFlag) break;
		}	
}

template<class T>
void Algorithm<T>::selectionSort(T *array, std::size_t length, int (*fCompare)(const T *, const T *))
{
		if(0 == *array || 0 == length) return;
		
		for(int nLoop = 0; nLoop < length - 1; nLoop ++)
		{
				int minKey = nLoop;
				
				for(int index = nLoop + 1; index < length; index ++)
				{
					  if(fCompare(&array[minKey], &array[index]) > 0)
						{
							minKey = index;
						}
				}
				
				if(minKey != nLoop)
				{
					T temp = array[minKey];
					array[minKey] = array[nLoop];
					array[nLoop]	= temp;
				}
		}
}

template<class T>
void Algorithm<T>::quickSort(T *array, std::size_t nLow, std::size_t nHigh, int (*fCompare)(const T *, const T *))
{
		if(0 == *array || nLow >= nHigh) return ;
		
		int nFirst = nLow;
		int nLast  = nHigh;
		T nKey = array[nFirst];//设定一个key值用来划分数据，比key值小的在它的左边，比它大的在它右边
		
		while(nFirst < nLast)
		{
			//从右边开始找比key值小的数,如果比key值大则下标向左移
			while(nFirst < nLast && fCompare(&nKey, &array[nLast]) <= 0)
			{
					-- nLast;
			}
			//把比key值小的元素赋值给数组的一个元素
			array[nFirst] = array[nLast];
			
			//从左边开始找比key大的数，如果比key值小则下标向右移动
			while(nFirst < nLast && fCompare(&nKey, &array[nFirst])  >= 0)
			{
					++ nFirst;
			}
			//把比key值打的元素赋值给最后一个元素
			array[nLast] = array[nFirst];
		}
		array[nFirst] = nKey;
		quickSort(array, nLow, nFirst - 1, fCompare);//对小于key的左边区域再排序
		quickSort(array, nFirst + 1, nHigh, fCompare);//对大于key的区域再排序
}

template<class T>
void Algorithm<T>::insertSort(T *array, std::size_t nLength, int (*fCompare)(const T*, const T*))
{
		if(0 == *array || nLength <= 0) return;
			
		T temp;
		int index = 0;
		
		for(int nLoop = 1; nLoop < nLength; nLoop ++)
		{
			temp = array[nLoop];
			
			for(index = nLoop; index > 0 && fCompare(&array[index - 1], &temp) > 0; index --)
			{
				array[index] = array[index -1];	
			
			}	
			array[index] = temp;
			
		}
}

template<class T>
void Algorithm<T>::binaryInsertSort(T *array, std::size_t nLength, int (*fCompare)(const T*, const T*))
{
	 if(0 == *array || nLength <= 0) return;
	 	
	 
	 for(int nLoop = 1; nLoop < nLength; nLoop ++)
	 {
	 		T temp = array[nLoop];
	 		
	 		int nLow  = 0;
	 		int nHigh = nLoop - 1;
	 		
	 		while(nLow <= nHigh)
	 		{
	 			int nMid = (nLow + nHigh) / 2;
	 			
	 			if(fCompare(&temp, &array[nMid]) > 0)
	 			{
	 				nLow = nMid + 1;	
	 			}	
	 			else
	 			{
	 				nHigh = nMid - 1;
	 			}
	 		}
	 		
	 		for(int index = nLoop; index > nLow; index --)
	 		{
	 			array[index] = array[index - 1]; 			
	 		}
	 		array[nLow] = temp;	
	 }
}