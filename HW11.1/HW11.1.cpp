
#include <iostream>

const int ROWS = 3;
const int COLUMNS = 3;

bool find(int arr_2d[ROWS][COLUMNS], int toFind) 
{
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLUMNS; ++j) 
        {
            std::cout << arr_2d[i][j] << " ";
            if (arr_2d[i][j] == toFind) 
            {
                std::cout << "Element found ";
                return true;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Element not found\n";
    return false;
}

int main() 
{
    int toFind=0;
    int arr_2d[ROWS][COLUMNS] =
    {
        1,2,3,
        4,5,6,
        7,8,9
    };

    std::cout << "To find : ";
    std::cin >> toFind;
    find(arr_2d, toFind);

}


