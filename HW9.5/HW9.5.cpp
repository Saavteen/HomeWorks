
#include <iostream>

bool isEqual(const char str1[], const char str2[])
{
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    if (length1 != length2)
    {
        std::cout << "they are not equal";
        return false;
    }
    for (int i=0;i<length1;i++)
    {
        if (str1[i] != str2[i])
        {
            std::cout << "they are not equal";
            return false;
        }

    }
    std::cout << "they are equal";
    return true;
}

int main()
{
    const int lineSize = 25;
    char line1[lineSize];

    std::cout << "first string: ";
    std::cin.getline(line1, lineSize);

    std::cout << "second string: ";

    char line2[lineSize];

    std::cin.getline(line2, lineSize);

    isEqual(line1, line2);

}

