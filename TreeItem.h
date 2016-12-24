#ifndef TREEITEM_H
#define TREEITEM_H

#include "Pentagon.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include <memory>
const int max_children_size = 4;
template <class T1, class T2, class T3>
class TreeItem
{
public:
	TreeItem();
	TreeItem(std::shared_ptr<T1> &pentagon);
	TreeItem(std::shared_ptr<T2> &rhombus);
	TreeItem(std::shared_ptr<T3> &trapeze);

	bool IsPentagon();
	bool IsRhombus();
	bool IsTrapeze();
	bool IsVisited();
	bool IsLeaf();

	std::shared_ptr<T1> GetPentagon();
	std::shared_ptr<T2> GetRhombus();
	std::shared_ptr<T3> GetTrapeze();
	double GetSquare();

	TreeItem* GetChild(int index);
	void SetChild(std::shared_ptr<T1> &pentagon, int index);
	void SetChild(std::shared_ptr<T2> &rhombus, int index);
	void SetChild(std::shared_ptr<T3> &trapeze, int index);

	bool operator < (TreeItem &rhs);
	bool operator > (TreeItem &rhs);

	bool visited = 0;
	TreeItem<T1, T2, T3>* children[max_children_size];
	template <class T1, class T2, class T3> friend std::ostream& operator << (std::ostream &os, TreeItem<T1, T2, T3> item);
	double square;
	std::shared_ptr<T1> pentagon;
	std::shared_ptr<T2> rhombus;
	std::shared_ptr<T3> trapeze;
private:
	

	

	
	
};


#endif
