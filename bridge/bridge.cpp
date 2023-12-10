#include <QPainter>
#include <memory>
#include <vector>

class IDrawing {
public:
    virtual void draw(QPainter *painter) = 0;
    virtual ~IDrawing() {}
};

class Rectangle : public IDrawing {
public:
    void draw(QPainter *painter) override {
        painter->drawRect(10, 10, 100, 100);
    }
};

class Circle : public IDrawing {
public:
    void draw(QPainter *painter) override {
        painter->drawEllipse(10, 10, 100, 100);
    }
};

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw(QPainter *painter) = 0;
};

class QtShape : public Shape 
{
public:
    QtShape(std::shared_ptr<IDrawing> drawing)
        : drawing(drawing) {}
    
    void draw(QPainter *painter) override 
    {
        drawing->draw(painter);
    }

private:
    std::shared_ptr<IDrawing> drawing;
};


int main() {
    QPainter painter;
    std::vector<std::shared_ptr<QtShape>> shapes;
    shapes.push_back(std::make_shared<QtShape>(std::make_shared<Rectangle>()));
    shapes.push_back(std::make_shared<QtShape>(std::make_shared<Circle>()));

    for (auto& shape : shapes) {
        shape->draw(&painter);
    }

    return 0;
}