#pragma once
#include <cassert>

template <class T>
class OrderedArray
{
public:
	// Constructor
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocated new array
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	// Destructor
	~OrderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;		// Good programming practice to set unused pointers to NULL
		}
	}

	// Insertion -- Big-O = O(N)
	int push(T val)
	{
		assert(m_array != NULL);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = m_numElements; k > i; k--)	// Moving backwards through the array starting at m_numElements
		{
			m_array[k] = m_array[k - 1];
		}

		// Step 3: Insert val into index
		m_array[i] = val;

		m_numElements++;

		return i;
	}

	// Deletion (2 methods)
	// Remove the last item in the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}

	// Remove at a specific index
	void remove(int index)
	{
		assert(m_array != NULL);

		if (index >= m_numElements)
		{
			return;
		}

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}

		m_numElements--;
	}

	// Searching -- Binary Search -- Big-O = O(log N)
	int search(T searchKey)
	{
		//Call to the binary search recursive function
		//Binary search: searchkey, initial lowerbound, initial upperbound
		return binarySearch(searchKey, 0, m_numElements - 1);
	}

	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}

	// Clear -- Big-O = O(1)
	void clear()
	{
		m_numElements = 0;
	}

	// Gets and Sets
	int getSize()
	{
		return m_numElements;
	}

	int getMaxSize()
	{
		return m_maxSize;
	}

	int getGrowSize()
	{
		return m_growSize;
	}

	void setGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}

private:
	//Recursive Binary Search
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(m_array != NULL);
		assert(lowerBound >= 0);
		assert(upperBound < m_numElements);

		//Bitwise divide by 2
		int current = (lowerBound + upperBound) >> 1; //2^2 == >>1

		//Did we find the searchKey at current
		if(m_array[current] == searchKey)
		{
			return current;
		}
		else if(lowerBound > upperBound)
		{
			//Did not find
			return -1;
		}
		else
		{
			if(m_array[current] < searchKey)
			{
				//Search upper half of array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				//Search lower half of array
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}

		return -1;
	}
	
	// Expand
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;
		m_array = temp;
		temp = NULL;

		m_maxSize += m_growSize;

		return true;
	}
private:
	// Variables
	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;		// Maximum size of my array
	int m_growSize;		// Amount the array can grow through expansion
	int m_numElements;	//Number of items currently in my array
};