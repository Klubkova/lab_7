#ifndef NTREE_H
#define NTREE_H

#include "TreeItem.cpp"

const int max_nodes = 5;

template <class T1, class T2, class T3>
class NTree
{
public:
	NTree();
	TreeItem<T1, T2, T3>* Insert(std::shared_ptr<T1> &pentagon);
	TreeItem<T1, T2, T3>* Insert(std::shared_ptr<T2> &rhombus);
	TreeItem<T1, T2, T3>* Insert(std::shared_ptr<T3> &trapeze);

	bool IsFull();
	bool IsEmpty();

	TreeItem<T1, T2, T3>* GetRoot();

	TreeItem<T1, T2, T3>* FindMin(TreeItem<T1, T2, T3>* p);
	void Display(TreeItem<T1, T2, T3>* root);

	void Sort(TreeItem<T1, T2, T3>* root);
	void QuickSort(TreeItem<T1, T2, T3>* array[], int L, int R);

	TreeItem<T1, T2, T3>* DeleteBySquare(TreeItem<T1, T2, T3>* root, double square);

	TreeItem<T1, T2, T3>* DeletePentagon(TreeItem<T1, T2, T3>* root);
	TreeItem<T1, T2, T3>* DeleteRhombus(TreeItem<T1, T2, T3>* root);
	TreeItem<T1, T2, T3>* DeleteTrapeze(TreeItem<T1, T2, T3>* root);

	TreeItem<T1, T2, T3>* DeleteRecPentagon(TreeItem<T1, T2, T3>* root);
	TreeItem<T1, T2, T3>* DeleteRecRhombus(TreeItem<T1, T2, T3>* root);
	TreeItem<T1, T2, T3>* DeleteRecTrapeze(TreeItem<T1, T2, T3>* root);
	TreeItem<T1, T2, T3>* root;
	int size;
private:
	

};

#endif
