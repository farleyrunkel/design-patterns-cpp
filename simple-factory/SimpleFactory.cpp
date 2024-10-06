#include <iostream>
#include <string>

/*
 * Product
 * products implement the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class Product
{
public:
    virtual ~Product() {}

    virtual std::string productName() = 0;
    // ...
};

/*
 * Concrete Product
 * define product to be created
 */
class ConcreteProductA : public Product
{
public:
    ~ConcreteProductA() {}

    std::string productName()
    {
        return "type A";
    }
    // ...
};

/*
 * Concrete Product
 * define product to be created
 */
class ConcreteProductB : public Product
{
public:
    ~ConcreteProductB() {}

    std::string productName()
    {
        return "type B";
    }
    // ...
};

/*
 * Simple Factory
 * contains a static method for creating products
 */
class SimpleFactory
{
public:
    static Product* createProduct(const std::string& type)
    {
        if (type == "A") {
            return new ConcreteProductA();
        }
        else if (type == "B") {
            return new ConcreteProductB();
        }
        return nullptr; // Invalid product type
    }

    // ...
};

int main()
{
    Product* p1 = SimpleFactory::createProduct("A");
    if (p1) {
        std::cout << "Product: " << p1->productName() << std::endl;
        delete p1; // Don't forget to free memory
    }

    Product* p2 = SimpleFactory::createProduct("B");
    if (p2) {
        std::cout << "Product: " << p2->productName() << std::endl;
        delete p2; // Don't forget to free memory
    }

    return 0;
}
