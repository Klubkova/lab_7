#include "NTreeArray.h"

template <class T1, class T2, class T3> NTreeArray<T1, T2, T3>::NTreeArray(int size)
{
	data = new NTree<T1, T2, T3>[size];
	NTreeArray<T1, T2, T3>::size = size;
}

template <class T1, class T2, class T3> void NTreeArray<T1, T2, T3>::Insert(std::shared_ptr<T1> &pentagon)
{
	for (int i = 0; i < size; i++)
	{
		if (!data[i].IsFull())
		{
			data[i].Insert(pentagon);
			return;
		}
	}
}

template <class T1, class T2, class T3> void NTreeArray<T1, T2, T3>::Insert(std::shared_ptr<T2> &rhombus)
{
	for (int i = 0; i < size; i++)
	{
		if (!data[i].IsFull())
		{
			data[i].Insert(rhombus);
			return;
		}
	}
}

template <class T1, class T2, class T3> void NTreeArray<T1, T2, T3>::Insert(std::shared_ptr<T3> &trapeze)
{
	for (int i = 0; i < size; i++)
	{
		if (!data[i].IsFull())
		{
			data[i].Insert(trapeze);
			return;
		}
	}
}

template <class T1, class T2, class T3> void NTreeArray<T1, T2, T3>::DeleteByType(char type)
{
	for (int i = 0; i < size; i++)
	{
		if(type=='p') data[i].root = data[i].DeletePentagon(data[i].root);
		else if (type=='r') data[i].root = data[i].DeleteRhombus(data[i].root);
		else if (type=='t') data[i].root = data[i].DeleteTrapeze(data[i].root);
	}
}

template <class T1, class T2, class T3> void NTreeArray<T1, T2, T3>::DeleteBySquare(double square)
{
	for (int i = 0; i < size; i++)
	{
		data[i].root=data[i].DeleteBySquare(data[i].root,square);
	}
}
template <class T1, class T2, class T3> void NTreeArray<T1, T2, T3>::Display()
{
	for (int i = 0; i < size; i++)
	{
		std::cout <<"["<< i <<"] "<<"size="<<data[i].size<<std::endl;
		data[i].Display(data[i].GetRoot());
		}
}
