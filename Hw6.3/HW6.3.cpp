
#include <iostream>

int main()
{
	unsigned int factorial=0,F=1;

	std::cout << "Enter your Factrorial :";
	std::cin >> factorial;

	for (unsigned int a = 1; a <= factorial; ++a)
	{
		F *= a;
		std::cout << F << " ";
		
	}
}

