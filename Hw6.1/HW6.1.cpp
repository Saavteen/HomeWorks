#include <iostream>

int main() {
    int firstTerm, step, lastTerm;

  
    std::cout << "Enter the first term: ";
    std::cin >> firstTerm;

    std::cout << "Enter step : ";
    std::cin >> step;

    std::cout << "Enter the number of terms: ";
    std::cin >> lastTerm;

    
    std::cout << "Arithmetic progression: " << firstTerm;


    int term = firstTerm;
    for (int i = 2; i <= lastTerm; ++i) 
    {
        term += step;
        std::cout << ", " << term;
    }

    std::cout << std::endl;

    return 0;
}