
#include <iostream>
#include <algorithm>


int main() 
{
    int size;

    // Зчитування розміру сторін (або кількості рядків) з консолі
    std::cout << "Enter ammount of rows : ";
    std::cin >> size;

    // Виведення прямокутника
    std::cout << "rectangle " << size << " x " << size << ":\n";
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

     //Виведення прямокутного трикутника
    std::cout << "\n Triangle v1 " << size << ":\n";
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j <= i; ++j) 
        {
            std::cout << "* ";
        }  
        std::cout << std::endl;
    }
    
    std::cout << "\n Triangle v2 " << size << ":\n";
    int size1 = size;
    for (int i = size1; i >= 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n square +1 " << size << ":\n";    
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << "* ";
        }

        std::cout << std::endl;

        for (int h = 0; h <= i; ++h)
        {
            std::cout << " ";
        }   
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0,a=0,b=1; j < i; ++j)
        {
            std::swap(a, b);
            std::cout << a;
        }
        std::cout << std::endl;
    }

    return 0;
}
