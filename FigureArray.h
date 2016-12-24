// заголовки методов класса FigureArray
#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H
//#include "Trapeze.h"
//#include "Pentagon.h"
//#include "Rhombus.h"
//#include "ArrayItem.cpp"
#include "Iterator.cpp"
#include <memory>
template <class T1, class T2, class T3>
class FigureArray
{
public:
	FigureArray(int size); // конструктор

	void Insert(std::shared_ptr<T1> &pentagon, int index);
	void Insert(std::shared_ptr<T2> &rhombus, int index);
	void Insert(std::shared_ptr<T3> &trapeze, int index);

	bool IsPentagon(int index);
	bool IsRhombus(int index);
	bool IsTrapeze(int index);

	std::shared_ptr<T1> GetPentagon(int index);
	std::shared_ptr<T2> GetRhombus(int index);
	std::shared_ptr<T3> GetTrapeze(int index);

	Iterator<T1, T2, T3> begin();
	Iterator<T1, T2, T3> end();

	void Delete(int index);
	template <class T1, class T2, class T3> friend std::ostream& operator << (std::ostream &os, FigureArray<T1,T2,T3> &array);
	virtual ~FigureArray(); // деструктор

private:
	ArrayItem<T1,T2,T3> *data; // указатель на массив
	int size; // размер массива
	Iterator<T1, T2, T3> first;
	Iterator<T1, T2, T3> last;
};

//#include "FigureArray.cpp"
#endif

