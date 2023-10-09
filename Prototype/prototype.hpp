#include <iostream>
#include <memory>


class Shape {
public:
    virtual ~Shape() {}
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

class Circle : public Shape {
private:
    int x;
    int y;
    int radius;
public:
    Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}

    std::unique_ptr<Shape> clone() const override
    {
        return std::make_unique<Circle>(*this);
    }

    void draw() const override
    {
        std::cout << "Drawing Circle"<< std::endl;
    }
};

int main()
{
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(1, 2, 3);
    circle->draw();

    std::unique_ptr<Shape> circle2 = circle->clone();
    circle2->draw();

}
