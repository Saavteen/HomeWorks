#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstddef>   



class Vector2d
{
public:

    static int activeInstances;


    //constructor
    Vector2d(float x=0.0,float y=0.0)
    {
        m_x = x;
        m_y = y;

        ++activeInstances;
    }
    //destructor
    ~Vector2d()
    {
        --activeInstances;
    }
   
     /* Vector2d operator+(const Vector2d& vector2)const
    {
        return Vector2d(m_x + vector2.m_x, m_y + vector2.m_y);
    }*/

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);

    Vector2d operator-(const Vector2d& vector2)
    {
        return Vector2d(m_x - vector2.m_x, m_y - vector2.m_y);
    }

    void operator*=(float scalar)
    {
        m_x *= scalar;
        m_y *= scalar;
    }

    float operator()()
    {
        return std::sqrt(m_x * m_x + m_y * m_y);
    }

    float& operator[](std::size_t idx) 
{
        if (idx == 0) 
            return m_x;
        else if (idx == 1) 
            return m_y;
        else 
            ("Index out of range");
    }

    static int getActiveInstances() 
    {
        return activeInstances;
    }

    void print()
    {
        //TO DO
        std::cout << std::endl;
        std::cout << "{"<<m_x<<";"<<m_y<<"}";
        //std::cout << "Vector 2 : ";
    }

    float m_x;
    float m_y;
}; 

int Vector2d::activeInstances = 0;

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
    //std::cout << "calling friend operator";
    return Vector2d(leftVector.m_x + rightVector.m_x, leftVector.m_y + rightVector.m_y);
}

int main()
{
    float testVecX, testVecY ;
    float testVecX2, testVecY2;
    float scalar;

     std::cout << "Enter X and Y for Vector 1 : ";
     std::cin >> testVecX >> testVecY;
     std::cout << "Enter X and Y for Vector 2 : ";
     std::cin >> testVecX2 >> testVecY2;
     std::cout << "Enter scalar : ";
     std::cin >> scalar;


    Vector2d vector1(testVecX, testVecY);
    Vector2d vector2(testVecX2, testVecY2);
    Vector2d vectorSum = vector1 + vector2;
    Vector2d vectorSubstract = vector1 - vector2;
    vector1 *= scalar;

    std::cout << "Summary of Vector1 and Vector2: ";
    vectorSum.print();
    std::cout << "\nSubstraction of Vector1 and Vector2: ";
    vectorSubstract.print();
    std::cout << "\nMultiply of Vector1 and Scalar: ";
    vector1.print();
    std::cout << "\nLength of Vector2: " << vector2() << std::endl;

    std::cout << "Vector1 [0]  " << vector1[0] << std::endl;
    std::cout << "Vector1 [1]  " << vector1[1] << std::endl;

    vector1[0] = 5.0;
    vector1[1] = 6.0;

    std::cout << "Modified Vector1 : ";
    vector1.print();

    std::cout << "\nActive instances: " << Vector2d::getActiveInstances() << std::endl;

}
