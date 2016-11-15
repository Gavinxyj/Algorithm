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
void Algorihm<T>::bubbleSort(T *array, size_t nLen)
{
		if(0 == *array || 0 == nLen) return;

		for(int nLoop = 0; nLoop < nLen -1; nLoop ++)
		{
			for(int index = nLoop + 1; index < nLen; index ++)
			{
					if(array[nLoop] > array[index])
					{
						T temp = array[nLoop];
						array[nLoop] = array[index];
						array[index]  = temp;
					}
			}	
		}	
}

