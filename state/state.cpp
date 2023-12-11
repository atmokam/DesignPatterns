#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

class State {
public:
    virtual ~State() {}
    virtual void handle() = 0;
    virtual std::string getColor() = 0;
};

class RedLightState : public State {
public:
    void handle() override {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    std::string getColor() override {
        return "Red";
    }


};

class YellowLightState : public State {
public:
    void handle() override {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    std::string getColor() override {
        return "Yellow";
    }
};

class GreenLightState : public State {
public:
    void handle() override {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    std::string getColor() override {
        return "Green";
    }
};

class TrafficLight {
private:
    std::unique_ptr<State> state;
public:
    TrafficLight(std::unique_ptr<State> state) : state(std::move(state)) {}

    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }

    void change() {
        std::cout << "Light is " << state->getColor() << std::endl;
        state->handle();
    }
};

