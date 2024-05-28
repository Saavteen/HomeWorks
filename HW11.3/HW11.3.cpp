
#include <iostream>

const int COLUMNS = 3, ROWS = 3;

enum class BypassArray
{
    UpToDown_RightToLeft,
    LeftToRight_DownToUp
};

void BypassArrayFunction(int array[ROWS][COLUMNS],BypassArray direction)
{
    if (direction == BypassArray::UpToDown_RightToLeft)
    {
        for (int i = COLUMNS-1; i >=0; i--)
        {
            for (int j = 0; j <ROWS ; j++)
            {
                std::cout << array[j][i];
                //надіюсь я правильно зрозумів завдання
            }
            std::cout << std::endl;
        }
    }
    else //(direction == BypassArray::LeftToRight_DownToUp)
    {
        for (int i = ROWS-1; i >=0; i--)
        {
            if ((i % 2) == 0)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    std::cout << array[i][j];
                }
                std::cout << std::endl;
            }
            else 
            {
                for (int j =COLUMNS-1; j >= 0; j--)
                {
                    std::cout << array[i][j];
                }
                std::cout << std::endl;
            }
        }
    }
}

int main()
{

    int array[ROWS][COLUMNS] =
    {
        1,2,3,
        4,5,6,
        7,8,9
    };
    BypassArrayFunction(array, BypassArray::UpToDown_RightToLeft);
    std::cout << std::endl;
    BypassArrayFunction(array, BypassArray::LeftToRight_DownToUp);
}
