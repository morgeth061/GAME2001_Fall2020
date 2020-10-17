#include <iostream>
#include "OrderedArray.h"

int main()
{
	std::cout << "Recursive Binary Search Example" << std::endl;

	OrderedArray<int> array(3);

	//Test the expansion of the array
	array.push(43);
	array.push(6);
	array.push(23);
	array.push(94);
	array.push(17);
	array.push(83);
	array.push(44);
	array.push(28);

	std::cout << "Ordered Array Contents:";

	for (int i = 0; i < array.getSize(); i++)
	{
		std::cout << " " << array[i];
	}

	//Test the search
	std::cout << "Search for 43 was found at index ";
	std::cout << array.search(43) << std::endl;
}