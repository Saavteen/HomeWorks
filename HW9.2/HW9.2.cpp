
#include <iostream>

void toUpperCase(char str[],int size)
{
	for (int i = 0; i < size; ++i) 
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
		}
		
		std::cout << str[i];
	}
}	


int main()
{
constexpr unsigned LINE_SIZE = 25;
	char line[LINE_SIZE];
	std::cin.getline(line, LINE_SIZE-1);
	toUpperCase(line, LINE_SIZE);
}

