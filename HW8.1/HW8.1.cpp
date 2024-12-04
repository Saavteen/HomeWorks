
#include <iostream>

void function(int ammountOfNumbers)
{
	while (true)
	{
		int number=0,positive=0,negative=0,zero=0;

		for (int i=0 ;i < ammountOfNumbers; i++)
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
		std::cout << "positive : " << positive <<"\n";
		std::cout << "negative : " << negative << "\n";
		std::cout << "zero : " << zero << "\n";
	}
}

int main()
{
	int rounds=0;
	std::cout << "Enter ammount of numbers: ";
	std::cin >> rounds;
	function(rounds);
}


