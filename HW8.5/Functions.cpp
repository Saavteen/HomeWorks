#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Functions.h"


//functions from task 1 
void function(int ammountOfNumbers)
{
	while (true)
	{
		int number = 0, positive = 0, negative = 0, zero = 0;

		for (int i = 0; i < ammountOfNumbers; i++)
		{
			std::cout << "Input your number : ";
			std::cin >> number;
			if (number > 0)
			{
				positive++;
			}
			else if (number < 0)
			{
				negative++;
			}
			else
			{
				zero++;
			}
		}
		std::cout << "positive : " << positive << "\n";
		std::cout << "negative : " << negative << "\n";
		std::cout << "zero : " << zero << "\n";
	}
}

//functions from task 2
int factorial(int count)
{
	int F = 1;

	for (int a = 1; a <= count; ++a)
	{
		F *= a;
		std::cout << F << " ";

	}
	return F;
}

//functions from task 3
void printNaturalNumbersLessToHigh(int count)
{
	for (int i = 0; i <= count; i++)
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

//funtions from task 4
float getArea(float radius)
{
	float  s = M_PI * (radius * radius);
	std::cout << "square = " << s << "\n";
	return s;
}

float getCircumference(float radius)
{
	float i = (M_PI * M_PI) * radius;
	std::cout << "Length = " << i << "\n";
	return i;
}