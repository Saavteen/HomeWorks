
#include <iostream>

class Rectangle
{
public:

	Rectangle()
	{
		std::cout << "default";
	}

	Rectangle(float length, float height)
	{
		std::cout << "2 properties";
		m_length=length;
		m_height=height;
	}

	float getArea();
	float getPerimeter();
	void print();

	float m_length=0;
	float m_height=0;

};

float Rectangle::getArea()
{
	return m_length * m_height;
}

float Rectangle::getPerimeter()
{
	return 2 * (m_length + m_height);
}

void Rectangle::print()
{
	std::cout << std::endl;
	std::cout << "Area: " << getArea() << std::endl;
	std::cout << "Perimeter: " << getPerimeter() << std::endl;
}

int main ()
{
	//default 
	Rectangle myRectangle;
	myRectangle.m_length = 2;
	myRectangle.m_height = 4;
	
	myRectangle.print();

	//two properties

	Rectangle Rectangle2(3, 5);
	Rectangle2.print();
}
