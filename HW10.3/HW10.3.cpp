
#include <iostream>

bool find(const int* arr, int size, int elem)
{
	for(int i = 0; i < size; i++)
	{
		if (arr[i] == elem)
		{
			std::cout << "We find it in"<<i;
			return true;
		}

	}
	std::cout << "we dont found it ((";
	return false;

}

int main()
{
	const int size = 5;
	int array[size];
	int searchedElem = 3;

	std::cout << "string: ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> array[i];
	}

	find(array, size, searchedElem);
}


