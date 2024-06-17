#include <iostream>
#include <string>

const int TABLES_COUNT = 10;
const int MENU_ITEMS_COUNT = 4;

class Coffee 
{
public:
    std::string name;
    double price;

    Coffee()
    {
        name = "";
        price = 0.0;
    }

    Coffee(const std::string& name, double price)
    {
        this->name = name;
        this->price = price;
    }
};


class CoffeeShop {
private:
    std::string m_Name;
    bool m_Tables[TABLES_COUNT];
    Coffee* m_Orders[TABLES_COUNT];

public:

    CoffeeShop(const std::string& name)
    {
        m_Name = name;
        for (int i = 0; i < TABLES_COUNT; ++i)
        {
            m_Tables[i] = false; 
            m_Orders[i] = nullptr; 
        }
    }

    bool isTableFree(int tableNumber) const
    {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT)
        {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        return !m_Tables[tableNumber];
    }

    bool occupyTable(int tableNumber)
    {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT)
        {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (m_Tables[tableNumber])
        {
            std::cerr << "Table is already occupied." << std::endl;
            return false;
        }
        m_Tables[tableNumber] = true;
        return true;
    }

    bool freeTable(int tableNumber)
    {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT)
        {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (!m_Tables[tableNumber])
        {
            std::cerr << "Table is already free." << std::endl;
            return false;
        }
        m_Tables[tableNumber] = false;
        delete m_Orders[tableNumber]; 
        m_Orders[tableNumber] = nullptr;
        return true;
    }

    bool addOrder(int tableNumber, const Coffee& coffee)
    {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT)
        {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (!m_Tables[tableNumber])
        {
            std::cerr << "Table is free, please occupy it first." << std::endl;
            return false;
        }
        if (m_Orders[tableNumber] != nullptr)
        {
            std::cerr << "Table already has an order." << std::endl;
            return false;
        }
        m_Orders[tableNumber] = new Coffee(coffee);
        return true;
    }

    void printInfo() const
    {
        std::cout << "Shop name: " << m_Name << std::endl;
        for (int i = 0; i < TABLES_COUNT; ++i)
        {
            std::cout << "Table " << i << ": " << (m_Tables[i] ? "Occupied" : "Free");
            if (m_Orders[i] != nullptr)
            {
                std::cout << ", Order: " << m_Orders[i]->name << " - " << m_Orders[i]->price << " UAH";
            }
            std::cout << std::endl;
        }
    }

    ~CoffeeShop()
    {
        for (int i = 0; i < TABLES_COUNT; ++i)
        {
            delete m_Orders[i];
        }
    }

    int takePlace()
    {
        for (int i = 0; i < TABLES_COUNT; ++i)
        {
            if (!m_Tables[i])
            {
                m_Tables[i] = true;
                return i;
            }
        }
        return -1; 
    }

    void order(int tableNumber)
    {
        Coffee menu[MENU_ITEMS_COUNT] = {
            Coffee("Latte", 50.0),
            Coffee("Espresso", 30.0),
            Coffee("Cappuccino", 45.0),
            Coffee("Americano", 35.0)
        };

        std::cout << "Drink menu:" << std::endl;
        for (int i = 0; i < MENU_ITEMS_COUNT; ++i)
        {
            std::cout << i + 1 << ". " << menu[i].name << " - " << menu[i].price << " UAH" << std::endl;
        }

        std::cout << "Enter the drink number: ";
        int choice;
        std::cin >> choice;

        if (choice < 1 || choice > MENU_ITEMS_COUNT)
        {
            std::cerr << "Invalid choice." << std::endl;
            return;
        }

        addOrder(tableNumber, menu[choice - 1]);
    }

    bool prepare(int tableNumber)
    {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT)
        {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (m_Orders[tableNumber] == nullptr)
        {
            std::cerr << "Table has not placed an order yet." << std::endl;
            return false;
        }

        std::cout << "Order for table " << tableNumber << " (" << m_Orders[tableNumber]->name << ") is being prepared." << std::endl;
        return true;
    }

    bool getReceipt(int tableNumber)
    {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT)
        {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (m_Orders[tableNumber] == nullptr)
        {
            std::cerr << "Order does not exist." << std::endl;
            return false;
        }

        std::cout << "Receipt for table " << tableNumber << ": " << m_Orders[tableNumber]->price << " UAH" << std::endl;
        freeTable(tableNumber);
        return true;
    }
};

int main()
{
    CoffeeShop myCoffeeShop("My Coffee Shop");

    int tableNumber = myCoffeeShop.takePlace();
    if (tableNumber != -1)
    {
        std::cout << "Occupied table number " << tableNumber << std::endl;
        myCoffeeShop.order(tableNumber);
        myCoffeeShop.prepare(tableNumber);
        myCoffeeShop.getReceipt(tableNumber);
    }
    else
    {
        std::cout << "No free tables." << std::endl;
    }

    myCoffeeShop.printInfo();

    return 0;
}
