#include "TreeItem.h"

template <class T1, class T2, class T3> TreeItem<T1,T2,T3>::TreeItem() : pentagon(nullptr), rhombus(nullptr), trapeze(nullptr)
{
	for (int i = 0; i < max_children_size; i++) children[i] = nullptr;
	square = 0;
}

template <class T1, class T2, class T3> TreeItem<T1, T2, T3>::TreeItem(std::shared_ptr<T1> &pentagon) : pentagon(pentagon), rhombus(nullptr), trapeze(nullptr)
{
	for (int i = 0; i < max_children_size; i++) children[i] = nullptr;
	square = pentagon->Square();
}

template <class T1, class T2, class T3> TreeItem<T1, T2, T3>::TreeItem(std::shared_ptr<T2> &rhombus) : pentagon(nullptr), rhombus(rhombus), trapeze(nullptr)
{
	for (int i = 0; i < max_children_size; i++) children[i] = nullptr;
	square = rhombus->Square();
}

template <class T1, class T2, class T3> TreeItem<T1, T2, T3>::TreeItem(std::shared_ptr<T3> &trapeze) : pentagon(nullptr), rhombus(nullptr), trapeze(trapeze)
{
	for (int i = 0; i < max_children_size; i++) children[i] = nullptr;
	square = trapeze->Square();
}

template <class T1, class T2, class T3> bool TreeItem<T1, T2, T3>::IsPentagon()
{
	if (pentagon != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool TreeItem<T1, T2, T3>::IsRhombus()
{
	if (rhombus != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool TreeItem<T1, T2, T3>::IsTrapeze()
{
	if (trapeze != nullptr) return true;
	else return false;
}
template <class T1, class T2, class T3> bool TreeItem<T1, T2, T3>::IsVisited()
{
	return visited;
}
template <class T1, class T2, class T3> bool TreeItem<T1, T2, T3>::IsLeaf()
{
	bool flag = 1;
	for (int i = 0; i < max_children_size; i++)
	{
		if (children[i]) flag = 0;
	}
	return flag;
}
template <class T1, class T2, class T3> std::shared_ptr<T1> TreeItem<T1, T2, T3>::GetPentagon()
{
	return this->pentagon;
}
template <class T1, class T2, class T3> std::shared_ptr<T2> TreeItem<T1, T2, T3>::GetRhombus()
{
	return this->rhombus;
}
template <class T1, class T2, class T3> std::shared_ptr<T3> TreeItem<T1, T2, T3>::GetTrapeze()
{
	return this->trapeze;
}
template <class T1, class T2, class T3> TreeItem<T1,T2,T3>* TreeItem<T1, T2, T3>::GetChild(int index)
{
	if (!children[index]) return 0;
	else return children[index];
}
template <class T1, class T2, class T3> double TreeItem<T1, T2, T3>::GetSquare()
{
	return square;
}
template <class T1, class T2, class T3> void TreeItem<T1, T2, T3>::SetChild(std::shared_ptr<T1> &pentagon, int index)
{
	children[index] = new TreeItem<T1,T2,T3>(pentagon);
}
template <class T1, class T2, class T3> void TreeItem<T1, T2, T3>::SetChild(std::shared_ptr<T2> &rhombus, int index)
{
	children[index] = new TreeItem<T1, T2, T3>(rhombus);
}
template <class T1, class T2, class T3> void TreeItem<T1, T2, T3>::SetChild(std::shared_ptr<T3> &trapeze, int index)
{
	children[index]= new TreeItem<T1, T2, T3>(trapeze);
}
template <class T1, class T2, class T3> bool TreeItem<T1, T2, T3>::operator <(TreeItem &rhs)
{
	if (square < rhs.square) return true;
	else return false;
}
template <class T1, class T2, class T3> bool TreeItem<T1, T2, T3>::operator >(TreeItem &rhs)
{
	if (square > rhs.square) return true;
	else return false;
}
template <class T1, class T2, class T3> std::ostream& operator << (std::ostream &os, TreeItem<T1, T2, T3> item)
{
	if (item.IsPentagon()) os << *item.pentagon << " square="<<item.square<< " (I am pentagon)";
	else if (item.IsRhombus()) os << *item.rhombus << " square=" << item.square << " (I am rhombus)";
	else if (item.IsTrapeze()) os << *item.trapeze << " square=" << item.square << " (I am trapeze)";
	else os << "empty";
	return os;
}