
#include <iostream>

enum class SortingDirection 
{ 
  ascending, 
  descending 
};

bool isSorted(const int* arr, int size, SortingDirection direction)
{
    for (int i=0;i<size;i++)
    {
        if (direction == SortingDirection::ascending)
        {
            if (arr[i - 1] > arr[i])
            {
                return false;
            }
        }
        else
        {
            if (arr[i - 1] < arr[i])
            {
                return false;
            }
        }
    }   
    return true;
}



int main()
{
    const int maxSize=6;
    int arr[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "is sorted in ascending order : " << (isSorted(arr, maxSize, SortingDirection::ascending) ? "true" : "false\n Its sorted in descending order ") << std::endl;
}

