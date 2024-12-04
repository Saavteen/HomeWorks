#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "recursionFunctions.h"

//functioons from task 2
int factorialRecursion(int count)
{
	if (count == 0 || count == 1)
	{
		return 1;
	}
	return count * factorialRecursion(count - 1);
}


//functioons from task 3
void printNaturalNumbersRecursionLessToHigh(int count)
{
	if (count > 9 || count < 0)
	{
		return;
	}
	std::cout << count;
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
