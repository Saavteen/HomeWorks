
#include<iostream>
#include <string>

const int TABLES_COUNT = 10;
const int MENU_ITEMS_COUNT = 4;

enum class DrinkType {
    Coffee,
    Tea
};

enum class CoffeeType {
    Americano,
    Latte,
    Espresso,
    Cappuccino
};

enum class TeaType {
    Black,
    Green
};

enum class DrinkSize {
    Small,
    Medium,
    Large,
    ExtraLarge
};


class Drink {
public:
    std::string name;
    double price;
    DrinkType type;

    Drink(const std::string& name, double price, DrinkType type)
        : name(name), price(price), type(type) {}
};

class CoffeeDrink : public Drink {
public:
    CoffeeType coffeeType;

    CoffeeDrink(CoffeeType type, DrinkSize size)
        : Drink(getCoffeeName(type, size), getCoffeePrice(type, size), DrinkType::Coffee), coffeeType(type) {}

private:
    static std::string getCoffeeName(CoffeeType type, DrinkSize size) {
        std::string sizeStr = getSizeString(size);
        switch (type) {
        case CoffeeType::Americano:
            return "Americano" + sizeStr;
        case CoffeeType::Latte:
            return "Latte" + sizeStr;
        case CoffeeType::Espresso:
            return "Espresso";
        case CoffeeType::Cappuccino:
            return "Cappuccino" + sizeStr;
        default:
            return "Unknown";
        }
    }

    static double getCoffeePrice(CoffeeType type, DrinkSize size) {
        switch (type) {
        case CoffeeType::Americano:
            return 35.0; // Example prices
        case CoffeeType::Latte:
            return getSizePrice(size, 50.0, 60.0, 70.0, 80.0);
        case CoffeeType::Espresso:
            return 30.0;
        case CoffeeType::Cappuccino:
            return getSizePrice(size, 45.0, 55.0, 65.0, 75.0);
        default:
            return 0.0;
        }
    }

    static std::string getSizeString(DrinkSize size) {
        switch (size) {
        case DrinkSize::Small:
            return " (S)";
        case DrinkSize::Medium:
            return " (M)";
        case DrinkSize::Large:
            return " (L)";
        case DrinkSize::ExtraLarge:
            return " (XL)";
        default:
            return "";
        }
    }

    static double getSizePrice(DrinkSize size, double smallPrice, double mediumPrice, double largePrice, double extraLargePrice) {
        switch (size) {
        case DrinkSize::Small:
            return smallPrice;
        case DrinkSize::Medium:
            return mediumPrice;
        case DrinkSize::Large:
            return largePrice;
        case DrinkSize::ExtraLarge:
            return extraLargePrice;
        default:
            return 0.0;
        }
    }
};

class TeaDrink : public Drink {
public:
    TeaType teaType;

    TeaDrink(TeaType type, DrinkSize size)
        : Drink(getTeaName(type, size), getTeaPrice(type, size), DrinkType::Tea), teaType(type) {}

private:
    static std::string getTeaName(TeaType type, DrinkSize size) {
        std::string sizeStr = getSizeString(size);
        switch (type) {
        case TeaType::Black:
            return "Black Tea" + sizeStr;
        case TeaType::Green:
            return "Green Tea" + sizeStr;
        default:
            return "Unknown";
        }
    }

    static double getTeaPrice(TeaType type, DrinkSize size) {
        switch (type) {
        case TeaType::Black:
            return getSizePrice(size, 20.0, 25.0, 30.0, 35.0);
        case TeaType::Green:
            return getSizePrice(size, 25.0, 30.0, 35.0, 40.0);
        default:
            return 0.0;
        }
    }

    static std::string getSizeString(DrinkSize size) {
        // Implementation similar to CoffeeDrink
    }

    static double getSizePrice(DrinkSize size, double smallPrice, double mediumPrice, double largePrice, double extraLargePrice) {
        // Implementation similar to CoffeeDrink
    }
};
//class Coffee
//{
//public:
//    std::string name;
//    double price;
//
//    Coffee()
//    {
//        name = "";
//        price = 0.0;
//    }
//
//    Coffee(const std::string& name, double price)
//    {
//        this->name = name;
//        this->price = price;
//    }
//};


class CoffeeShop {
private:
    std::string m_Name;
    bool m_Tables[TABLES_COUNT];
    Drink* m_Orders[TABLES_COUNT];

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

    bool addOrder(int tableNumber, const Drink& coffee)
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
        m_Orders[tableNumber] = new Drink(coffee);
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
        Drink menu[MENU_ITEMS_COUNT] = {
        CoffeeDrink(CoffeeType::Latte, DrinkSize::Medium),
        CoffeeDrink(CoffeeType::Espresso, DrinkSize::Medium),
        CoffeeDrink(CoffeeType::Cappuccino, DrinkSize::Medium),
        CoffeeDrink(CoffeeType::Americano, DrinkSize::Medium)
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

    bool addOrder(int tableNumber, DrinkType drinkType, CoffeeType coffeeType, TeaType teaType, DrinkSize size)
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
        m_Orders[tableNumber] = createDrink(drinkType, coffeeType, teaType, size);
        return true;
    }

    void order(int tableNumber)
    {
        DrinkType type;
        std::cout << "Choose drink type (1 - Coffee, 2 - Tea): ";
        int drinkChoice;
        std::cin >> drinkChoice;

        if (drinkChoice == 1) {
            CoffeeType coffeeType;
            std::cout << "Choose coffee type (1 - Americano, 2 - Latte, 3 - Espresso, 4 - Cappuccino): ";
            int coffeeChoice;
            std::cin >> coffeeChoice;

            // Введіть обробку вибору розміру напою

            addOrder(tableNumber, DrinkType::Coffee, coffeeType, TeaType::Black, DrinkSize::Medium);
        }
        else if (drinkChoice == 2) {
            TeaType teaType;
            std::cout << "Choose tea type (1 - Black, 2 - Green): ";
            int teaChoice;
            std::cin >> teaChoice;

            // Введіть обробку вибору розміру напою

            addOrder(tableNumber, DrinkType::Tea, CoffeeType::Espresso, teaType, DrinkSize::Medium);
        }
        else {
            std::cerr << "Invalid choice." << std::endl;
        }
    }

    Drink* createDrink(DrinkType drinkType, CoffeeType coffeeType, TeaType teaType, DrinkSize size) {
        switch (drinkType) {
        case DrinkType::Coffee:
            return new CoffeeDrink(coffeeType, size);
        case DrinkType::Tea:
            return new TeaDrink(teaType, size);
        default:
            return nullptr;
        }
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