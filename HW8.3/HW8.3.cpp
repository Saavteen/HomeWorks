
#include <iostream>

void printNaturalNumbersLessToHigh(int count)
{
	for ( int i = 0; i <=count; i++)
	{
		if (i > 9)
		{
		 std::cout << "\neror";
		 return;
		}
		std::cout << i;
	}
}

void printNaturalNumbersHighToLess(int count)
{
	for (int i = 9; i >= count; i--)
	{
		if (i > 9)
		{
			std::cout << "\neror";
			return;
		}
		std::cout << i;
	}
}

void printNaturalNumbersRecursionLessToHigh(int count)
{
	if (count > 9 || count < 0)
	{
		return;
	}
	std::cout << count ;
	return printNaturalNumbersRecursionLessToHigh(count + 1);
}

void printNaturalNumbersRecursionHighToLess(int count)
{
	if (count > 9 || count < 0)
	{
		return;
	}
	 printNaturalNumbersRecursionHighToLess(count + 1);
	std::cout << count;
	return;
}

int main()
{
	int a,N;
	std::cout << "Enter 1 for (0to9 through do/while);\n Enter 2 for (9 to 0) through do while;\n Enter 3 for Recursion (0to9);\n Enter 4 for Recursion (9to0);\n";
	std::cin >> a;
	std::cout << "\nInput N ";
	std::cin >> N;
	if (N>9 || N<0)
	{
		std::cout << "Eror";
	}
	else
	{
		if (a == 1)
		{
			printNaturalNumbersLessToHigh(N);
		}
		else if (a == 2)
		{
			printNaturalNumbersHighToLess(N);
		}
		else if (a == 3)
		{
			printNaturalNumbersRecursionLessToHigh(N);
		}
		else
		{
			printNaturalNumbersRecursionHighToLess(N);
		}
	}
}



