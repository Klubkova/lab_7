#ifndef NTREEARRAY_H
#define NTREEARRAY_H
#include "NTree.cpp"

template <class T1, class T2, class T3>
class NTreeArray
{
public:
	NTreeArray(int size);

	void Insert(std::shared_ptr<T1> &pentagon);
	void Insert(std::shared_ptr<T2> &rhombus);
	void Insert(std::shared_ptr<T3> &trapeze);

	void DeleteByType(char type);
	void DeleteBySquare(double square);

	void Display();

private:
	NTree<T1,T2,T3>* data;
	int size;
};



#endif
