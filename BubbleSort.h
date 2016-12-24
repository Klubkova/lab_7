#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <cmath>
#include "TreeItem.h"
template <class T1,class T2,class T3>
void BubbleSort(TreeItem<T1,T2,T3> elements[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j <size - 1 - i; j++)
		{
			if (elements[j] > elements[j + 1])
			{
				swap(elements[j], elements[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

#endif
