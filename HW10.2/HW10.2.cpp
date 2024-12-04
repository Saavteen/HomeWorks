
#include <iostream>

bool calculateSum(const double* arr, int arrSize, double& sum)
{

    int a=0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    if (sum > 0)
    {
        std::cout << sum;
        return true;
    }
    else
    {
        std::cout << "eror less than 0";
        return false;
    }
}

int main()
{
    double sum = 0;
    const int lineSize = 5;
    double line[lineSize];

    std::cout << "string: ";
    for (int i = 0; i < lineSize; i++) 
    {
        std::cin >> line[i];  
    }
    calculateSum(line,lineSize,sum);

}
