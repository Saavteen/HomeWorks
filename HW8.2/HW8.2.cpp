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

int main()
{
	int F;
	std::cout << "Enter your number! : ";
	std::cin >> F;
	factorial(F);

}

