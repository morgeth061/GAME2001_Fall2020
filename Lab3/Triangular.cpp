#include <iostream>
#include <cassert>

//Triangle numbers with a loop
int triNumLoop(int term)
{
	int value = 0;

	for(; term > 0; term--)
	{
		value += term;
	}

	return value;
}

//Triangle numbers with recursion
int triNumRecursion(int term)
{
	assert(term >= 0);

	//base case
	if(term == 1)
	{
		return 1;
	}

	//Tail recursion
	return(triNumRecursion(term - 1) + term);
}

//Test function
int main()
{
	std::cout << "Triangle numbers example:" << std::endl;

	//using loops
	std::cout << "The value of the 18th term using a loop is: ";
	std::cout << triNumLoop(18) << std::endl;

	//Using recursion
	std::cout << "The value of the 18th term using recursion is: ";
	std::cout << triNumRecursion(18) << std::endl;

	return 0;
}