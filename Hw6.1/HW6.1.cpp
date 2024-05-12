#include <iostream>

int main()
{
    int a = 3, c = 0;

    for (a; c < 14; a += 2)
    {
        std::cout << a << "\t";
        c++;
    }
}