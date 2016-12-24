#include "NTree.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
template <class T1, class T2, class T3>
NTree<T1, T2, T3>::NTree() : 
	root(nullptr),
	size(0) {}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::Insert(std::shared_ptr<T1> &pentagon)
{
	std::queue <TreeItem<T1,T2,T3>*> nodes_to_visit;
	TreeItem<T1, T2, T3>* current_node;
	if (!root)
	{
		root = new TreeItem<T1, T2, T3>(pentagon);
		size++;
		return root;
	}
	else
	{
		nodes_to_visit.push(root);
		root->visited = true;
	}
	while (!nodes_to_visit.empty())
	{
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		for (int i = 0; i<max_children_size; i++)
		{
			if (!current_node->children[i])
			{
				current_node->children[i] = new TreeItem<T1, T2, T3>(pentagon);
				//Sort(current_node);
				size++;
				return root;
			}
			else
			{
				if (current_node->children[i]->square > pentagon->Square())
				{
					if (current_node->children[i]->IsPentagon())
					{
						std::shared_ptr<T1> pent = current_node->children[i]->pentagon;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(pentagon);
						return Insert(pent);
					}
					else if (current_node->children[i]->IsRhombus())
					{
						std::shared_ptr<T2> rhomb = current_node->children[i]->rhombus;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(pentagon);
						return Insert(rhomb);
					}
					else if (current_node->children[i]->IsTrapeze())
					{
						std::shared_ptr<T3> trap = current_node->children[i]->trapeze;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(pentagon);
						return Insert(trap);
					}
				}
				if (current_node->children[i]->visited == false)
				{
					nodes_to_visit.push(current_node->children[i]);
					current_node->children[i]->visited = true;
				}
			}
			
		}
	}
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::Insert(std::shared_ptr<T2> &rhombus)
{
	std::queue <TreeItem<T1, T2, T3>*> nodes_to_visit;
	TreeItem<T1, T2, T3>* current_node;
	if (!root)
	{
		root = new TreeItem<T1, T2, T3>(rhombus);
		size++;
		return root;
	}
	else
	{
		nodes_to_visit.push(root);
		root->visited = true;
	}
	while (!nodes_to_visit.empty())
	{
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		for (int i = 0; i<max_children_size; i++)
		{
			if (!current_node->children[i])
			{
				current_node->children[i] = new TreeItem<T1, T2, T3>(rhombus);
				size++;
				return root;
			}
			else
			{
				if (current_node->children[i]->square > rhombus->Square())
				{
					if (current_node->children[i]->IsPentagon())
					{
						std::shared_ptr<T1> pent = current_node->children[i]->pentagon;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(rhombus);
						return Insert(pent);
					}
					else if (current_node->children[i]->IsRhombus())
					{
						std::shared_ptr<T2> rhomb = current_node->children[i]->rhombus;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(rhombus);
						return Insert(rhomb);
					}
					else if (current_node->children[i]->IsTrapeze())
					{
						std::shared_ptr<T3> trap = current_node->children[i]->trapeze;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(rhombus);
						return Insert(trap);
					}
				}
				if (current_node->children[i]->visited == false)
				{
					nodes_to_visit.push(current_node->children[i]);
					current_node->children[i]->visited = true;
				}
			}
		}
	}
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::Insert(std::shared_ptr<T3> &trapeze)
{
	std::queue <TreeItem<T1, T2, T3>*> nodes_to_visit;
	TreeItem<T1, T2, T3>* current_node;
	if (!root)
	{
		root = new TreeItem<T1, T2, T3>(trapeze);
		size++;
		return root;
	}
	else
	{
		nodes_to_visit.push(root);
		root->visited = true;
	}
	while (!nodes_to_visit.empty())
	{
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		for (int i = 0; i<max_children_size; i++)
		{
			if (!current_node->children[i])
			{
				current_node->children[i] = new TreeItem<T1, T2, T3>(trapeze);
				//Sort(current_node);
				size++;
				return root;
			}
			else
			{
				if (current_node->children[i]->square > trapeze->Square())
				{
					if (current_node->children[i]->IsPentagon())
					{
						std::shared_ptr<T1> pent = current_node->children[i]->pentagon;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(trapeze);
						return Insert(pent);
					}
					else if (current_node->children[i]->IsRhombus())
					{
						std::shared_ptr<T2> rhomb = current_node->children[i]->rhombus;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(trapeze);
						return Insert(rhomb);
					}
					else if (current_node->children[i]->IsTrapeze())
					{
						std::shared_ptr<T3> trap = current_node->children[i]->trapeze;
						delete current_node->children[i];
						current_node->children[i] = new TreeItem<T1, T2, T3>(trapeze);
						return Insert(trap);
					}
				}
				if (current_node->children[i]->visited == false)
				{
					nodes_to_visit.push(current_node->children[i]);
					current_node->children[i]->visited = true;
				}
			}
		}
	}
}

template <class T1, class T2, class T3>
bool NTree<T1, T2, T3>::IsFull()
{
	
	if (size == max_nodes) return true;
	else return false;
}

template <class T1, class T2, class T3>
bool NTree<T1, T2, T3>::IsEmpty()
{
	if (!root) return 1;
	else return 0;
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::GetRoot()
{
	return root;
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::FindMin(TreeItem<T1, T2, T3>* p)
{
	for (int i = 0; i < max_children_size; i++)
	{
		if (p->children[i])
		{
			if (p->children[i]->IsLeaf())
			{
				TreeItem<T1, T2, T3>* q = p->children[i];
				//cout << q << endl;
				p->children[i] = 0;
				return q;
			}
			else FindMin(p->children[i]);
		}
	}
}

template <class T1, class T2, class T3>
void NTree<T1, T2, T3>::Display(TreeItem<T1, T2, T3>* root)
{
	if (!root) return;
	static int level = 0;
	level++;
	if (root)
	{
		
		std::cout << "\\__" << *root << std::endl;
		for (int j = 0; (j<max_children_size); j++)
		{
			if (root->children[j])
			{
				for (int i = 0; i < level; i++)
				{
					printf("   ");
				}
				Display(root->children[j]);
				
			}
		}
	}
	else std::cout << "empty" << std::endl;
	level--;
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::DeleteBySquare(TreeItem<T1, T2, T3>* root, double square)
{
	if (!root) return 0;
	if (root->square != square)
	{
		for (int i = 0; i < max_children_size; i++) root->children[i] = DeleteBySquare(root->children[i], square);
		return root;
	}
	else
	{
		if (root->IsLeaf())
		{
			delete root;
			size--;
			return 0;
		}
		else
		{
			TreeItem<T1, T2, T3>* min= FindMin(root);
			root->square = min->square;
			root->pentagon = min->pentagon;
			root->rhombus = min->rhombus;
			root->trapeze = min->trapeze;
			size--;
			return root;
		}
	}
}
template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::DeletePentagon(TreeItem<T1, T2, T3>* root)
{
	if (!root) return 0;
	if (root)
	{
		for (int i = 0; i < max_children_size; i++)
		{
			if (root->children[i]) root->children[i]=DeletePentagon(root->children[i]);
		}
		root = DeleteRecPentagon(root);
	}
	return root;
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::DeleteRhombus(TreeItem<T1, T2, T3>* root)
{
	if (!root) return 0;
	if (root)
	{
		for (int i = 0; i < max_children_size; i++)
		{
			if (root->children[i]) root->children[i] = DeleteRhombus(root->children[i]);
		}
		root = DeleteRecRhombus(root);
	}
	return root;
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::DeleteTrapeze(TreeItem<T1, T2, T3>* root)
{
	if (!root) return 0;
	if (root)
	{
		for (int i = 0; i < max_children_size; i++)
		{
			if (root->children[i]) root->children[i] = DeleteTrapeze(root->children[i]);
		}
		root = DeleteRecTrapeze(root);
	}
	return root;
}
template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::DeleteRecPentagon(TreeItem<T1, T2, T3>* root)
{
	if (!root) return 0;
	if (!root->pentagon)
	{
		for (int i = 0; i < max_children_size; i++) root->children[i] = DeleteRecPentagon(root->children[i]);
		return root;
	}
	else
	{
		if (root->IsLeaf())
		{
			delete root;
			size--;
			return 0;
		}
		else
		{
			TreeItem<T1, T2, T3>* min = FindMin(root);
			root->square = min->square;
			root->pentagon = min->pentagon;
			root->rhombus = min->rhombus;
			root->trapeze = min->trapeze;
			size--;
			return root;
		}
	}
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::DeleteRecRhombus(TreeItem<T1, T2, T3>* root)
{
	if (!root) return 0;
	if (!root->rhombus)
	{
		for (int i = 0; i < max_children_size; i++) root->children[i] = DeleteRecRhombus(root->children[i]);
		return root;
	}
	else
	{
		if (root->IsLeaf())
		{
			delete root;
			size--;
			return 0;
		}
		else
		{
			TreeItem<T1, T2, T3>* min = FindMin(root);
			root->square = min->square;
			root->pentagon = min->pentagon;
			root->rhombus = min->rhombus;
			root->trapeze = min->trapeze;
			size--;
			return root;
		}
	}
}

template <class T1, class T2, class T3>
TreeItem<T1, T2, T3>* NTree<T1, T2, T3>::DeleteRecTrapeze(TreeItem<T1, T2, T3>* root)
{
	if (!root) return 0;
	if (!root->trapeze)
	{
		for (int i = 0; i < max_children_size; i++) root->children[i] = DeleteRecTrapeze(root->children[i]);
		return root;
	}
	else
	{
		if (root->IsLeaf())
		{
			delete root;
			size--;
			return 0;
		}
		else
		{
			TreeItem<T1, T2, T3>* min = FindMin(root);
			root->square = min->square;
			root->pentagon = min->pentagon;
			root->rhombus = min->rhombus;
			root->trapeze = min->trapeze;
			size--;
			return root;
		}
	}
}

template <class T1, class T2, class T3>
void NTree<T1, T2, T3>::QuickSort(TreeItem<T1, T2, T3>* array[], int L, int R)
{
	if (R<=L) return;

	int left = L;
	int right = R;

	TreeItem<T1, T2, T3> middle = *array[(right + left) / 2];

	do
		
	{
		while (*array[left] < middle) left++;
		while (*array[right] > middle) right--;

		if (left <= right)
		{
			if (*array[left]>*array[right]) std::swap(*array[left], *array[right]);
			left++;
			right--;
		}
	} while (left <= right);

	if (right > L) QuickSort(array, L, right);
	if (left < R) QuickSort(array, left, R);
}

template <class T1, class T2, class T3>
void NTree<T1, T2, T3>::Sort(TreeItem<T1, T2, T3>* root)
{
	if (root)
	{
		int k = 0;
		
		for (int i = 0; i < max_children_size; i++)
		{
			if (root->children[i])
			{
				Sort(root->children[i]);
				k++;
			}
		}
		QuickSort(root->children, 0, k-1);
	}
}



