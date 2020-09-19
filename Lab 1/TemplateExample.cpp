// "Generic" classes or functions
// Compate 2 "things". Return smallest. Return largest.

#include <iostream>

// Check 2 "things". Return smallest.

template <class T> 

T min_func(T lVal, T rVal)
{
	if (lVal > rVal)
	{
		return lVal;
	}
	
	return rVal;
}


// Check 2 "things". Return largest.
template <class T>

T max_func(T lVal, T rVal)
{
	if (lVal < rVal)
	{
		return lVal;
	}

	return rVal;
}

// Implement a template class here
template <class T>

class TemplateClass
{
public:
	TemplateClass(T val)
	{
		m_val = val;
	}

	// OVERLOADED OPERATORS
	bool operator<(TemplateClass& rVal)
	{
		return m_val < rVal.getVal();
	}
	bool operator>(TemplateClass& rVal)
	{
		return m_val > rVal.getVal();
	}

	T getVal()
	{
		return m_val;
	}
private:
	T m_val;
};

//Main
/*int main()
{
	std::cout << "Template Example" << std::endl << std::endl;
	std::cout << "Min = " << min_func(30, 26) << std::endl;
	std::cout << "Max = " << max_func(56.1, 43.6) << std::endl;

	// Create 2 "TemplateClass" objects and compare them.
	std::cout << "Max (objects) = " << max_func(TemplateClass<int>(7), TemplateClass<int>(4)).getVal();

	return 0;
}*/