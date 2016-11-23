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
		
		bool bFlag = true; //���￼����������������������ֱ���˳�ѭ��
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
		T nKey = array[nFirst];//�趨һ��keyֵ�����������ݣ���keyֵС����������ߣ�������������ұ�
		
		while(nFirst < nLast)
		{
			//���ұ߿�ʼ�ұ�keyֵС����,�����keyֵ�����±�������
			while(nFirst < nLast && fCompare(&nKey, &array[nLast]) <= 0)
			{
					-- nLast;
			}
			//�ѱ�keyֵС��Ԫ�ظ�ֵ�������һ��Ԫ��
			array[nFirst] = array[nLast];
			
			//����߿�ʼ�ұ�key������������keyֵС���±������ƶ�
			while(nFirst < nLast && fCompare(&nKey, &array[nFirst])  >= 0)
			{
					++ nFirst;
			}
			//�ѱ�keyֵ���Ԫ�ظ�ֵ�����һ��Ԫ��
			array[nLast] = array[nFirst];
		}
		array[nFirst] = nKey;
		quickSort(array, nLow, nFirst - 1, fCompare);//��С��key���������������
		quickSort(array, nFirst + 1, nHigh, fCompare);//�Դ���key������������
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