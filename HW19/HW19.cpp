
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "DynamicIntArray.h"

void testDynamicIntArray() {
    std::cout << "Testing DynamicIntArray..." << std::endl;

    // Test default constructor
    DynamicIntArray arr1;
    std::cout << "Default constructor: size = " << arr1.getSize() << std::endl;

    // Test constructor with size
    DynamicIntArray arr2(5);
    std::cout << "Constructor with size 5: size = " << arr2.getSize() << std::endl;

    // Test setSize
    arr2.setSize(10);
    std::cout << "After setSize(10): size = " << arr2.getSize() << std::endl;

    // Test push_back
    for (int i = 0; i < 10; ++i) {
        arr2.push_back(i);
    }
    std::cout << "After push_back 10 elements: size = " << arr2.getSize() << std::endl;

    // Test operator[]
    for (std::size_t i = 0; i < arr2.getSize(); ++i) {
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }

    // Test clear
    arr2.clear();
    std::cout << "After clear: size = " << arr2.getSize() << std::endl;

    // Test copy constructor
    DynamicIntArray arr3 = arr2;
    std::cout << "Copy constructor: arr3 size = " << arr3.getSize() << std::endl;

    // Test copy assignment operator
    DynamicIntArray arr4(2);
    arr4 = arr3;
    std::cout << "Copy assignment operator: arr4 size = " << arr4.getSize() << std::endl;

    // Test comparison operators
    std::cout << "arr3 == arr4: " << (arr3 == arr4) << std::endl;
    std::cout << "arr3 != arr4: " << (arr3 != arr4) << std::endl;

}


int main()
{
    testDynamicIntArray();
}