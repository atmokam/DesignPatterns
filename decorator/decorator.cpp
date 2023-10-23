#include <iostream>
#include <string>
#include <memory>
#include <iomanip>


class Cake
{
public:
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
};


class BasicCake : public Cake
{
public:
    std::string getDescription() const override
    {
        return "Basic Cake";
    }

    double getCost() const override
    {
        return 999999.99; // price, in dollars
    }
};


class CakeDecorator : public Cake
{
public:
    CakeDecorator(std::shared_ptr<Cake> cake) : cake(cake) {}

protected:
    std::shared_ptr<Cake> cake;
};


class ToppingDecorator : public CakeDecorator
{
public:
    ToppingDecorator(std::shared_ptr<Cake> cake) : CakeDecorator(cake) {}

    std::string getDescription() const override
    {
        return cake->getDescription() + " + topping";
    }

    double getCost() const override
    {
        return cake->getCost() + 299;
    }
};


class FillingDecorator : public CakeDecorator
{
public:
    FillingDecorator(std::shared_ptr<Cake> cake) : CakeDecorator(cake) {}

    std::string getDescription() const override
    {
        return cake->getDescription() + "+ filling";
    }

    double getCost() const override
    {
        return cake->getCost() + 399;
    }
};

int main(){
    std::shared_ptr<Cake> cake = std::make_shared<BasicCake>();
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(0);
    std::cout << cake->getDescription() << " costs $" << cake->getCost() << std::endl;

    cake = std::make_shared<ToppingDecorator>(cake);
    std::cout << cake->getDescription() << " costs $" << cake->getCost() << std::endl;

    cake = std::make_shared<FillingDecorator>(cake);
    std::cout << cake->getDescription() << " costs $" << cake->getCost() << std::endl;

    return 0;
}