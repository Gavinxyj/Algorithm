#ifndef _ALGORIHM_
#define _ALGORIHM_

template<class T>
class Algorithm
{
public:
	Algorithm();
	~Algorithm();
public:
	void bubbleSort(T *array, std::size_t nLen, int (*fCompare)(const T *, const T *));
	
	void selectionSort(T *array, std::size_t length, int (*fCompare)(const T *, const T *));
		
	void quickSort(T *array, std::size_t nFirst, std::size_t nLast, int (*fCompare)(const T *, const T *));

};

#endif