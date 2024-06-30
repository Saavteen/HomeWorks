
#include <iostream>

enum class CoffeeType
{
	Latte,
	Americano,
	Cappuccino
};

class Coffee 
{
public:

	Coffee(CoffeeType type)
	{
        m_type = type;

        switch (type)
        {
        case CoffeeType::Latte:
            m_price = 15;
            break;
        case CoffeeType::Americano:
            m_price = 10;
            break;
        case CoffeeType::Cappuccino:
            m_price = 20;
            break;
        default:
            m_price = 0; 
            break;
        }

	}

	CoffeeType getType()const
    {
        return m_type;
    }

	int getPrice()
    {
        return m_price;
    }

    void print()
    {
        std::string typeName;
        int time;
        switch (m_type)
        {
        case CoffeeType::Latte:
            typeName = "Latte";
            time = 5;
            break;
        case CoffeeType::Americano:
            typeName = "Americano";
            time = 7;
            break;
        case CoffeeType::Cappuccino:
            typeName = "Cappuccino";
            time = 4;
            break;
        default:
            typeName = "Unknown";
            break;
        }
        std::cout << "Coffee Type: " << typeName << ", Price: $" << m_price<<", Minutes : "<< time<< std::endl;
    }

    
private:
	
	CoffeeType m_type;
	int m_price;
};

int main()
{

    Coffee latte(CoffeeType::Latte);
    Coffee americano(CoffeeType::Americano);
    Coffee cappuccino(CoffeeType::Cappuccino);

    latte.print();
    americano.print();
    cappuccino.print();

}


