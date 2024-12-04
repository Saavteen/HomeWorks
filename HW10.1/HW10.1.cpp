
#include <iostream>

void swap(int& a, int& b)
{
    int temporary =a;
    a = b;
    b = temporary;
    std::cout <<"after swap : " << a << " " << b <<"\n";
}

void swap(int* a, int* b)
{
    int temporary = *a;
    *a = *b;
    *b = temporary;
    std::cout << "after swap : " << *a << " " << *b;
}

int main()
{
    int a = 0, b = 0;
    std::cout << "enter 2 numbers : ";
    std::cin >> a >> b;
    swap(a, b);
    swap(&a, &b);
}




