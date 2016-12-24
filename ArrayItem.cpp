#ifndef ARRAYITEM_CPP
#define ARRAYITEM_CPP


#include "ArrayItem.h"
template <class T1, class T2, class T3> ArrayItem<T1, T2, T3>::ArrayItem() : pentagon(nullptr), rhombus(nullptr), trapeze(nullptr) {}
template <class T1, class T2, class T3> ArrayItem<T1,T2,T3>::ArrayItem(int index) : pentagon(nullptr), rhombus(nullptr), trapeze(nullptr), index(index) {}
template <class T1, class T2, class T3> ArrayItem<T1, T2, T3>::ArrayItem(std::shared_ptr<T1> &pentagon, int index) : pentagon(pentagon), rhombus(nullptr), trapeze(nullptr), index(index) {}
template <class T1, class T2, class T3> ArrayItem<T1, T2, T3>::ArrayItem(std::shared_ptr<T2> &rhombus, int index) : pentagon(nullptr), rhombus(rhombus), trapeze(nullptr), index(index) {}
template <class T1, class T2, class T3> ArrayItem<T1, T2, T3>::ArrayItem(std::shared_ptr<T3> &trapeze, int index) : pentagon(nullptr), rhombus(nullptr), trapeze(trapeze), index(index){}

template <class T1, class T2, class T3> bool ArrayItem<T1, T2, T3>::IsPentagon()
{
	if (pentagon != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool ArrayItem<T1, T2, T3>::IsRhombus()
{
	if (rhombus != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool ArrayItem<T1, T2, T3>::IsTrapeze()
{
	if (trapeze != nullptr) return true;
	else return false;
}

template <class T1, class T2, class T3> std::shared_ptr<T1> ArrayItem<T1, T2, T3>::GetPentagon()
{
	return this->pentagon;
}
template <class T1, class T2, class T3> std::shared_ptr<T2> ArrayItem<T1, T2, T3>::GetRhombus()
{
	return this->rhombus;
}
template <class T1, class T2, class T3> std::shared_ptr<T3> ArrayItem<T1, T2, T3>::GetTrapeze()
{
	return this->trapeze;
}
template <class T1, class T2, class T3> void ArrayItem<T1, T2, T3>::SetIndex(int index)
{
	ArrayItem<T1, T2, T3>::index = index;
}

template <class T1, class T2, class T3> int ArrayItem<T1, T2, T3>::GetIndex()
{
	return index;
}
//template <class T1, class T2, class T3> ArrayItem<T1, T2, T3> ArrayItem<T1, T2, T3>::operator = (ArrayItem<T1, T2, T3> array_item)
//{
//	pentagon = array_item.pentagon;
//	rhombus= array_item.rhombus;
//	trapeze = array_item.trapeze;
//	index = array_item.index;
//
//	return *this;
//}
template <class T1, class T2, class T3> std::ostream& operator << (std::ostream &os, ArrayItem<T1, T2, T3> &item)
{
	if (item.IsPentagon()) os << *item.pentagon << " (I am pentagon)";
	else if(item.IsRhombus()) os << *item.rhombus << " (I am rhombus)";
	else if (item.IsTrapeze()) os << *item.trapeze << " (I am trapeze)";
	else os << "empty";
	return os;
}

//template <class T1, class T2, class T3> ArrayItem<T1, T2, T3>::~ArrayItem()
//{
//	ArrayItem<T1, T2, T3>::ArrayItem();
//}
#endif
