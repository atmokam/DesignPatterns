#include <iostream>
#include <vector>
#include <memory>
// refactoring.guru example


// Component
class Graphic
{
public:
    virtual ~Graphic() {}
    virtual void draw() const = 0;
};

// Leaf
class Circle : public Graphic
{
public:
    void draw() const override
    {
        std::cout << "Draw Circle" << std::endl;
    }
};

// Composite
class GraphicGroup : public Graphic
{
public:
    void draw() const override
    {
        for (auto& obj : objects)
        {
            obj->draw();
        }
    }

    void add(std::unique_ptr<Graphic> graphic)
    {
        objects.push_back(std::move(graphic));
    }

private:
    std::vector<std::unique_ptr<Graphic>> objects;
};

int main()
{
    std::unique_ptr<Graphic> circle = std::make_unique<Circle>();
    std::unique_ptr<GraphicGroup> group = std::make_unique<GraphicGroup>();

    group->add(std::move(circle));
    group->draw();
    
    return 0;
}