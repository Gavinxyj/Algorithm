#ifndef _ALGORIHM_
#define _ALGORIHM_

template<class T>
class Algorithm
{
public:
	Algorithm();
	~Algorithm();
public:
	void bubbleSort(T *array, int nLen, int (*fCompare)(const T *, const T *));
	
	void selectionSort(T *array, int length, int (*fCompare)(const T *, const T *));
		
	void quickSort(T *array, int nFirst, int nLast, int (*fCompare)(const T *, const T *));
	
	void insertSort(T *array, int nLength, int (*fCompare)(const T*, const T*));

	void binaryInsertSort(T *array, int nLength, int (*fCompare)(const T*, const T*));
	
	void shellSort(T *array, int nLength, int (*fCompare)(const T*, const T*));
		
	void mergeSort(T *array, T *tempArray, int nFirst, int nLast, int (*fCompare)(const T*, const T*));
	
	void radixSort(T *array, int nLength);
	
	void heapSort(T *array, int nLength, int (*fCompare)(const T*, const T*));
	
private:
	void merge(T *array, T *tempArray, int nFirst, int nMid,  int nLast, int (*fCompare)(const T*, const T*));
	
	void adjustHeap(T *array, int nLength, T element, int (*fCompare)(const T*, const T*));
	
	void swap(T &firstElement, T &secondElement);
};

#endif