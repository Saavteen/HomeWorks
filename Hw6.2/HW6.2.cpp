#include <iostream>

int main()
{
	int F = 0, F1 = 1, F2 = 1, sum, next, End = 2, inputEnd;

	std::cout << "enter your Fibbonachi number : ";
	std::cin >> inputEnd;

	std::cout << F << "\t" << F1 << "\t ";

	while (End < inputEnd)
	{
		sum = F + F1;
		F = F1;
		std::cout << sum << "\t";
		F1 = sum;

		End++;
	}
}

