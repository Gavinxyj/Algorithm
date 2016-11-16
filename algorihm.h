#ifndef _ALGORIHM_
#define _ALGORIHM_

template<class T>
class Algorihm
{
public:
	Algorihm();
	~Algorihm();
public:
	void bubbleSort(T *array, std::size_t nLen, int (*Compare)(const T *, const T *));
	
	void selectionSort(T *array, std::size_t length, int (*Compare)(const T *, const T *));
};

#endif