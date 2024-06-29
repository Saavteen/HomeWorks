#include <iostream>
#include <string>

const int TABLES_COUNT = 10;

class Drink {
public:
    std::string name;
    double price;

    Drink(const std::string& name, double price) : name(name), price(price) {}
    virtual ~Drink() = default;
};

class Coffee : public Drink {
public:
    Coffee(const std::string& name, double price) : Drink(name, price) {}
};

class Tea : public Drink {
public:
    Tea(const std::string& name, double price) : Drink(name, price) {}
};

class Americano : public Coffee {
public:
    Americano(const std::string& size) : Coffee("Americano " + size, 35.0) {}
};

class Latte : public Coffee {
public:
    Latte(const std::string& size) : Coffee("Latte " + size, size == "M" ? 50.0 : size == "L" ? 60.0 : 70.0) {}
};

class Espresso : public Coffee {
public:
    Espresso() : Coffee("Espresso", 30.0) {}
};

class Cappuccino : public Coffee {
public:
    Cappuccino(const std::string& size) : Coffee("Cappuccino " + size, size == "M" ? 45.0 : 55.0) {}
};

class BlackTea : public Tea {
public:
    BlackTea(const std::string& size) : Tea("Black Tea " + size, size == "M" ? 20.0 : size == "L" ? 25.0 : 30.0) {}
};

class GreenTea : public Tea {
public:
    GreenTea(const std::string& size) : Tea("Green Tea " + size, size == "M" ? 25.0 : size == "L" ? 30.0 : 35.0) {}
};

class CoffeeShop {
private:
    std::string m_Name;
    bool m_Tables[TABLES_COUNT];
    Drink* m_Orders[TABLES_COUNT];

public:
    CoffeeShop(const std::string& name) : m_Name(name) {
        for (int i = 0; i < TABLES_COUNT; ++i) {
            m_Tables[i] = false;
            m_Orders[i] = nullptr;
        }
    }

    bool isTableFree(int tableNumber) const {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT) {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        return !m_Tables[tableNumber];
    }

    bool occupyTable(int tableNumber) {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT) {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (m_Tables[tableNumber]) {
            std::cerr << "Table is already occupied." << std::endl;
            return false;
        }
        m_Tables[tableNumber] = true;
        return true;
    }

    bool freeTable(int tableNumber) {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT) {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (!m_Tables[tableNumber]) {
            std::cerr << "Table is already free." << std::endl;
            return false;
        }
        m_Tables[tableNumber] = false;
        delete m_Orders[tableNumber];
        m_Orders[tableNumber] = nullptr;
        return true;
    }

    bool addOrder(int tableNumber, Drink* drink) {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT) {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (!m_Tables[tableNumber]) {
            std::cerr << "Table is free, please occupy it first." << std::endl;
            return false;
        }
        if (m_Orders[tableNumber] != nullptr) {
            std::cerr << "Table already has an order." << std::endl;
            return false;
        }
        m_Orders[tableNumber] = drink;
        return true;
    }

    void printInfo() const {
        std::cout << "Shop name: " << m_Name << std::endl;
        for (int i = 0; i < TABLES_COUNT; ++i) {
            std::cout << "Table " << i << ": " << (m_Tables[i] ? "Occupied" : "Free");
            if (m_Orders[i] != nullptr) {
                std::cout << ", Order: " << m_Orders[i]->name << " - " << m_Orders[i]->price << " UAH";
            }
            std::cout << std::endl;
        }
    }

    ~CoffeeShop() {
        for (int i = 0; i < TABLES_COUNT; ++i) {
            delete m_Orders[i];
        }
    }

    void order(int tableNumber) {
        std::cout << "Choose drink type (1 - Coffee, 2 - Tea): ";
        int drinkChoice;
        std::cin >> drinkChoice;

        std::string size;
        if (drinkChoice == 1) {
            std::cout << "Choose coffee type (1 - Americano, 2 - Latte, 3 - Espresso, 4 - Cappuccino): ";
            int coffeeChoice;
            std::cin >> coffeeChoice;

            if (coffeeChoice == 2 || coffeeChoice == 4 || coffeeChoice == 1) {
                std::cout << "Choose size (M, L, XL): ";
                std::cin >> size;
            }

            switch (coffeeChoice) {
            case 1: addOrder(tableNumber, new Americano(size)); break;
            case 2: addOrder(tableNumber, new Latte(size)); break;
            case 3: addOrder(tableNumber, new Espresso()); break;
            case 4: addOrder(tableNumber, new Cappuccino(size)); break;
            default: std::cerr << "Invalid choice." << std::endl; return;
            }
        }
        else if (drinkChoice == 2) {
            std::cout << "Choose tea type (1 - Black, 2 - Green): ";
            int teaChoice;
            std::cin >> teaChoice;

            std::cout << "Choose size (M, L, XL): ";
            std::cin >> size;

            switch (teaChoice) {
            case 1: addOrder(tableNumber, new BlackTea(size)); break;
            case 2: addOrder(tableNumber, new GreenTea(size)); break;
            default: std::cerr << "Invalid choice." << std::endl; return;
            }
        }
        else {
            std::cerr << "Invalid choice." << std::endl;
        }
    }

    bool prepare(int tableNumber) {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT) {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (m_Orders[tableNumber] == nullptr) {
            std::cerr << "Table has not placed an order yet." << std::endl;
            return false;
        }

        std::cout << "Order for table " << tableNumber << " (" << m_Orders[tableNumber]->name << ") is being prepared." << std::endl;
        return true;
    }

    bool getReceipt(int tableNumber) {
        if (tableNumber < 0 || tableNumber >= TABLES_COUNT) {
            std::cerr << "Invalid table number." << std::endl;
            return false;
        }
        if (m_Orders[tableNumber] == nullptr) {
            std::cerr << "Order does not exist." << std::endl;
            return false;
        }

        std::cout << "Receipt for table " << tableNumber << ": " << m_Orders[tableNumber]->price << " UAH" << std::endl;
        freeTable(tableNumber);
        return true;
    }
};

int main() {
    CoffeeShop myCoffeeShop("My Coffee Shop");
    int choice;

    do {
        std::cout << "\n1. Occupy table\n2. Order drink\n3. Prepare order\n4. Get receipt\n5. Print info\n6. Exit\nChoose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter table number to occupy (0-" << TABLES_COUNT - 1 << "): ";
            int tableNumber;
            std::cin >> tableNumber;
            myCoffeeShop.occupyTable(tableNumber);
        }
        else if (choice >= 2 && choice <= 4) {
            std::cout << "Enter table number (0-" << TABLES_COUNT - 1 << "): ";
            int tableNumber;
            std::cin >> tableNumber;

            if (choice == 2) {
                myCoffeeShop.order(tableNumber);
            }
            else if (choice == 3) {
                myCoffeeShop.prepare(tableNumber);
            }
            else if (choice == 4) {
                myCoffeeShop.getReceipt(tableNumber);
            }
        }
        else if (choice == 5) {
            myCoffeeShop.printInfo();
        }
        else if (choice != 6) {
            std::cerr << "Invalid choice." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
