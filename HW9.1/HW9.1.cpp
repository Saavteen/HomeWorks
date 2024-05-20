
#include <iostream>

void translateArray(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > 0)
		{
			numbers[i] *= 2;
		}
		else
		{
			numbers[i] = 0;
		}
	}
}

int main()
{
	int const size = 10;
	int array[size] = {};
	std::cout << "input 10 numbers : ";
	for (int a = 0; a < size; a++)
	{
		std::cin >> array[a];
	}
	translateArray(array, size);
	for (int a = 0; a < size; a++)
	{
		std::cout << array[a]<<" ";
	}
	return 0;
}
