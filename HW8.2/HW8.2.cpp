#include <iostream>

int factorial(int count)
{
	int F = 1;

	for ( int a = 1; a <= count; ++a)
	{
		F *= a;
		std::cout << F << " ";

	}
	return F;
}

int factorialRecursion(int count)
{
	if (count == 0 || count == 1)
	{
		return 1;
	}
	return count * factorialRecursion(count - 1);
}

int main()
{
	std::cout << "Enter your factorial number \n";
	int F;
	std::cout << "FIRST way to calculate Factorial \n";
	std::cin >> F;
	factorial(F);
	std::cout << "\n";
	std::cout << "SECOND way to calculate Factorial:" << std::endl;
	int recurFactorial = factorialRecursion(F); 
	std::cout << "Result: " << recurFactorial << std::endl;
}

