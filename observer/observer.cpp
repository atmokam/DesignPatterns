#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() {}
    virtual void update() = 0;
};

class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "ConcreteObserver: update received.\n";
    }
};

class Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
public:
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() {
        for (std::shared_ptr<Observer> observer : observers) {
            observer->update();
        }
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer;

    subject.attach(std::make_shared<ConcreteObserver>(observer));

    subject.notify();  

    return 0;
}