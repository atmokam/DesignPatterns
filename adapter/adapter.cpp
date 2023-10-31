#include <iostream>


class NewShape {
public:
    void draw() const {
        std::cout << "Drawing a NewShape." << std::endl;
    }

    void rotate() const {
        std::cout << "Rotating the NewShape." << std::endl;
    }

    void scale() const {
        std::cout << "Scaling the NewShape." << std::endl;
    }
};

class LegacyShape {
public:
    virtual void draw() const {
        std::cout << "Drawing a LegacyShape." << std::endl;
    }
};

class LegacyAdapter : public LegacyShape {
private:
    NewShape newShape; // via composition
public:
    LegacyAdapter(const NewShape& newShape) : newShape(newShape) {}

    virtual void draw() const override {
        newShape.draw();
    }
};