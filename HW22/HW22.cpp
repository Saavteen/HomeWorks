
#include <iostream>
#include "DynamicIntArray.h"

int main() 
{

    DynamicArray<int> intArray;

    intArray.push_back(10);
    intArray.push_back(20);
    intArray.push_back(30);

    std::cout << "intArray elements: ";
    for (std::size_t i = 0; i < intArray.getSize(); ++i) 
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    intArray.pop_back();
    std::cout << "intArray after pop_back: ";
    for (std::size_t i = 0; i < intArray.getSize(); ++i)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Last element: " << intArray.back() << std::endl;

    intArray.reserve(10);
    std::cout << "Capacity after reserve(10): " << intArray.getCapacity() << std::endl;

    intArray.shrinkToFit();
    std::cout << "Capacity after shrinkToFit(): " << intArray.getCapacity() << std::endl;

    DynamicArray<int> anotherArray = intArray;
    if (intArray == anotherArray)
    {
        std::cout << "intArray is equal to anotherArray" << std::endl;
    }
    else
    {
        std::cout << "intArray is not equal to anotherArray" << std::endl;
    }

    DynamicArray<std::string> stringArray;
    stringArray.push_back("Hello");
    stringArray.push_back("World");

    std::cout << "stringArray elements: ";
    for (std::size_t i = 0; i < stringArray.getSize(); ++i)
    {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
