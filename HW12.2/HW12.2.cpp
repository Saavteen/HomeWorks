#include <iostream>
#include <algorithm>

enum class SortingDirection
{
    ByRows,
    ByColumns
};

void sort(int arr[][4], int ROWS, int COLUMNS, SortingDirection direction)
{
    if (direction == SortingDirection::ByRows)
    {
        for (int i = 0; i < ROWS; ++i)
        {
            std::sort(arr[i], arr[i] + COLUMNS);
        }
    }
    else if (direction == SortingDirection::ByColumns)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            // Створюємо тимчасовий масив для сортування стовпця
            int temp[4];  // Використовуємо фіксований розмір
            for (int i = 0; i < ROWS; ++i)
            {
                temp[i] = arr[i][j];
            }
            // Сортуємо тимчасовий масив
            std::sort(temp, temp + ROWS);
            // Копіюємо відсортований стовпець назад у масив
            for (int i = 0; i < ROWS; ++i)
            {
                arr[i][j] = temp[i];
            }
        }
    }
}

void printArray(int arr[][4], int ROWS, int COLUMNS)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int ROWS = 4;
    const int COLUMNS = 4;
    int arr[ROWS][COLUMNS] =
    {
        {9, 2, 7, 3},
        {4, 8, 1, 5},
        {6, 0, 3, 2},
        {5, 9, 8, 1}
    };

    std::cout << "Original array:\n";
    printArray(arr, ROWS, COLUMNS);

    sort(arr, ROWS, COLUMNS, SortingDirection::ByRows);
    std::cout << "\nSorted by rows:\n";
    printArray(arr, ROWS, COLUMNS);

    sort(arr, ROWS, COLUMNS, SortingDirection::ByColumns);
    std::cout << "\nSorted by columns:\n";
    printArray(arr, ROWS, COLUMNS);

    return 0;
}
