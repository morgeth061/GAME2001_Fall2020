//Factorial: Ex: 9! = 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1
//Double Factorial: Ex: 9!! = 9 x 7 x 5x x3 x 1
#include <iostream>
#include <cassert>

//Single factorial
int factorial(int x)
{
	assert(x >= 0);

	//Base case
	if(x == 0)
	{
		return 1;
	}

	return (factorial(x - 1) * x);
}
//Double factorial
int doubleFactorial(int x)
{
	assert(x >= 0);

	//Base case
	if (x == 0 || x == 1)
	{
		return 1;
	}

	return (doubleFactorial(x - 2) * x);
}

//Main

int main()
{
	std::cout << "The factorial of 9 is: ";
	std::cout << factorial(9) << std::endl;

	std::cout << "The double factorial of 9 is: ";
	std::cout << doubleFactorial(9) << std::endl;

	return 0;
}