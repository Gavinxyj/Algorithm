#include<iostream>
#include "algorihm.h"

template<class T>
Algorihm<T>::Algorihm()
{
	
}

template<class T>
Algorihm<T>::~Algorihm()
{
	
}

template<class T>
void Algorihm<T>::bubbleSort(T *array, std::size_t nLen, int (*Compare)(const T *, const T *))
{
		if(0 == *array || 0 == nLen) return;
		
		bool bFlag = true; //这里考虑如果待排序列是有序的则直接退出循环
		for(int nLoop = 0; nLoop < nLen -1; nLoop ++)
		{		
			
			for(int index = 0; index < nLen - 1 - nLoop; index ++)
			{
					if(Compare(&array[index], &array[index + 1]) > 0)
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
void Algorihm<T>::selectionSort(T *array, std::size_t length, int (*Compare)(const T *, const T *))
{
		if(0 == *array || 0 == length) return;
		
		for(int nLoop = 0; nLoop < length - 1; nLoop ++)
		{
				int minKey = nLoop;
				
				for(int index = nLoop + 1; index < length; index ++)
				{
					  if(Compare(&array[minKey], &array[index]) > 0)
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
