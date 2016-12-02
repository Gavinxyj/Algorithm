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
void Algorithm<T>::bubbleSort(T *array, int nLen, int (*fCompare)(const T *, const T *))
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
void Algorithm<T>::selectionSort(T *array, int length, int (*fCompare)(const T *, const T *))
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
void Algorithm<T>::quickSort(T *array, int nLow, int nHigh, int (*fCompare)(const T *, const T *))
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
void Algorithm<T>::insertSort(T *array, int nLength, int (*fCompare)(const T*, const T*))
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
void Algorithm<T>::binaryInsertSort(T *array, int nLength, int (*fCompare)(const T*, const T*))
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

template<class T>
void Algorithm<T>::shellSort(T *array, int nLength, int (*fCompare)(const T*, const T*))
{
	 if(0 == *array || nLength <= 0) return;
		
	 for(int nLoop = nLength / 2; nLoop >= 1; nLoop /= 2)
	 {
	 		//������ΪnLoop������Ԫ�ؽ�������
	 		for(int index = nLoop; index < nLength; index ++)
	 		{
	 			 for(int nSwapIndex = index - nLoop; nSwapIndex >= 0; nSwapIndex -= nLoop)
	 			 {	 			 	  
	 			 		if(fCompare(&array[nSwapIndex], &array[index]) > 0)
	 			 		{ 
	 			 			 T temp = array[nSwapIndex];		 			
	 			 			 array[nSwapIndex] = array[index];
	 			 			 array[index]			 = temp;
	 			 		}
	 			 }	
	 		}	
	 }	
}

template<class T>
void Algorithm<T>::mergeSort(T *array, T *tempArray, int nFirst, int nLast, int (*fCompare)(const T*, const T*))
{
		if(0 == *array || (nFirst - nLast) > 0 || nFirst < 0 || nLast < 0 ) return;
		
		
		int nMidIndex = 0;
		
		if(nFirst < nLast)
		{
			  nMidIndex = (nFirst + nLast) / 2;
			 
				mergeSort(array, tempArray, nFirst, nMidIndex, fCompare);//�Էֽ���������н�������
				mergeSort(array, tempArray, nMidIndex + 1, nLast, fCompare);//�Էֽ����ұ����н�������
				merge(array, tempArray, nFirst, nMidIndex, nLast, fCompare);//�ϲ�����
		}
}

template<class T>
void Algorithm<T>::merge(T *array, T *tempArray, int nFirst, int nMid,  int nLast, int (*fCompare)(const T*, const T*))
{
		int nStartIndex = nFirst;
		int nMidIndex   = nMid + 1;
		int index 			= nFirst;
		
		while(nStartIndex != nMid + 1 && nMidIndex != nLast + 1)
		{
			if(fCompare(&array[nStartIndex], &array[nMidIndex]) > 0)
			{
				tempArray[index ++] = array[nMidIndex ++];	
			}
			else
			{
				tempArray[index ++] = array[nStartIndex ++];	
			}
		}
		
		while(nStartIndex != nMid + 1)
		{
			tempArray[index ++] = array[nStartIndex ++];	
		}
		
		while(nMidIndex != nLast + 1)
		{
			tempArray[index ++] = array[nMidIndex ++];	
		}
		
		for(nStartIndex = nFirst; nStartIndex <= nLast; nStartIndex ++)
		{
			array[nStartIndex] = tempArray[nStartIndex];	
		}
}