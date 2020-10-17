#include <iostream>

//Print down from a given number until we reach 1

void printNumReverse(int x)
{
	//Base case
	if(x <= 0)
	{
		return;
	}

	//The actual work this function has to do
	std::cout << " " << x;

	//Tail Recursion
	printNumReverse(x - 1);
}



/* int main()
{
	std::cout << "Recursion example" << std::endl;
	std::cout << "Here is a recursive call:" << std::endl;

	//Call a recursive function
	printNumReverse(5);

	return 0;
} */