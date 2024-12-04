
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

float getArea(float radius)
{
    float  s=M_PI*(radius*radius);
    std::cout << "square = " << s << "\n";
    return s;
}

float getCircumference(float radius)
{
    float i = (M_PI * M_PI) * radius;
    std::cout <<"Length = " << i << "\n";
    return i;
}

int main()
{
    float R;
    std::cout << "enter radius : ";
    std::cin >> R;
    getArea(R);
    getCircumference(R);
}
