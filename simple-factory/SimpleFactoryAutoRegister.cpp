#include <iostream>
#include <string>
#include <map>
#include <functional>

/*
 * Product
 * Products implement the same interface so that the classes can refer
 * to the interface, not the concrete product.
 */
class Product {
public:
    virtual ~Product() {}
};

/*
 * Simple Factory
 * Contains a static method for creating products.
 */
class SimpleFactory {
public:
    // Registers a product with the factory
    static void registerProduct(const std::string& type, std::function<Product* ()> creator) {
        productMap[type] = creator;
    }

    // Creates a product based on the registered type
    static Product* createProduct(const std::string& type) {
        auto it = productMap.find(type);
        if (it != productMap.end()) {
            return it->second();  // Call the creator function
        }
        return nullptr; // Invalid product type
    }

    // Static map to store product creators
    static std::map<std::string, std::function<Product* ()>> productMap;
};

// Static member definition
std::map<std::string, std::function<Product* ()>> SimpleFactory::productMap;

/*
 * Concrete Product A
 * Define product to be created.
 */
class ConcreteProductA : public Product {
public:
    ~ConcreteProductA() {}

    static std::string id() {
        return "A";
    }

    // Static method to register this product
    static void registerProduct();

    static Product* create() {
        return new ConcreteProductA();
    }

private:
    static bool autoRegister;  // Static variable for automatic registration
};

// Static variable definition with lambda for automatic registration
bool ConcreteProductA::autoRegister = []() {
    ConcreteProductA::registerProduct();
    return true;
    }();

void ConcreteProductA::registerProduct() {
    SimpleFactory::registerProduct(ConcreteProductA::id(), &ConcreteProductA::create);
}

/*
 * Concrete Product B
 * Define product to be created.
 */
class ConcreteProductB : public Product {
public:
    ~ConcreteProductB() {}

    static std::string id() {
        return "B";
    }

    // Static method to register this product
    static void registerProduct();

    static Product* create() {
        return new ConcreteProductB();
    }

private:
    static bool autoRegister;  // Static variable for automatic registration
};

// Static variable definition with lambda for automatic registration
bool ConcreteProductB::autoRegister = []() {
    ConcreteProductB::registerProduct();
    return true;
    }();

void ConcreteProductB::registerProduct() {
    SimpleFactory::registerProduct(ConcreteProductB::id(), &ConcreteProductB::create);
}


int main() {
    // Products are auto-registered, so you can create them immediately.
    Product* p1 = SimpleFactory::createProduct("A");
    if (p1) {
        std::cout << typeid(*p1).name() << std::endl;
        delete p1; // Don't forget to free memory
    }

    Product* p2 = SimpleFactory::createProduct("B");
    if (p2) {
        std::cout << typeid(*p2).name() << std::endl;
        delete p2; // Don't forget to free memory
    }

    Product* p3 = SimpleFactory::createProduct("C");
    if (p3) {
        std::cout << typeid(*p3).name() << std::endl;
        delete p3; // Don't forget to free memory
    }

    return 0;
}
