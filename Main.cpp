#include <iostream>
#include <cstdlib>
#include "Pentagon.h"
#include "Rhombus.h"
#include "Trapeze.h"
#include "NTreeArray.cpp"
//#include "Iterator.cpp"
int main()
{
	int x = 4;
	NTreeArray<Pentagon, Rhombus, Trapeze> ntree_array(10);
	std::cout << "[1] - insert, [2] - print, [3] - delete, [0] - exit" << std::endl;
	while (x != 0)
	{
		std::cout << "enter command: ";
		std::cin >> x;
		if (x == 1)
		{
			char figure_name;
			std::cout << "enter figure name ([p]-pentagon, [r]-rhombus, [t]-trapeze): ";
			std::cin >> figure_name;
			if (figure_name == 'p') ntree_array.Insert((std::shared_ptr<Pentagon>)(new Pentagon(std::cin)));
			else if (figure_name == 'r') ntree_array.Insert(std::shared_ptr<Rhombus>(new Rhombus(std::cin)));
			else if (figure_name == 't') ntree_array.Insert(std::shared_ptr<Trapeze>(new Trapeze(std::cin)));
		}
		else if (x == 2)
		{
			ntree_array.Display();
		}
		else if (x == 3)
		{
			char c;
			std::cout << "[s]-by square, [t]-by type: ";
			std::cin >> c;
			if (c == 's')
			{
				double square;
				std::cout << "enter square: ";
				std::cin >> square;
				ntree_array.DeleteBySquare(square);
			}
			else if (c == 't')
			{
				char type;
				std::cout << "enter figure type ([p]-pentagon, [r]-rhombus, [t]-trapeze): ";
				std::cin >> type;
				ntree_array.DeleteByType(type);
			}
		}
	}
	
	return 0;
}