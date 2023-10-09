#include <iostream>
#include <string>
#include <memory>

class Product
{
public:
    virtual ~Product() {}
    virtual void use() const = 0;
};

class ProductA : public Product
{
public:
    void use() const override
    {
        std::cout << "Using Product A" << std::endl;
    }
};

class ProductB : public Product
{
public:
    void use() const override
    {
        std::cout << "Using Product B" << std::endl;
    }
};

class ProductFactory
{
public:
    static std::unique_ptr<Product> createProduct(const std::string& productType)
    {
        if(productType == "A")
        {
            return std::make_unique<ProductA>();
        }
        else if(productType == "B")
        {
            return std::make_unique<ProductB>();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    std::unique_ptr<Product> productA = ProductFactory::createProduct("A");
    productA->use();

    std::unique_ptr<Product> productB = ProductFactory::createProduct("B");
    productB->use();

    return 0;
}