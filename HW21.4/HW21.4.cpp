#include <iostream>
#include <vector>
#include <algorithm>

unsigned int countDivisibleBy(const std::vector<int>& vec, int number) 
{
    return std::count_if(vec.begin(), vec.end(), [number](int x) 
        {
        return x % number == 0;
        });
}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,12 };
    
    int number = 2;
    unsigned int count = countDivisibleBy(numbers, number);

    std::cout << "Number of elements divisible by " << number << " is " << count << std::endl;

    return 0;
}
