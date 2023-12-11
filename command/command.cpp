#include <string>
#include <iostream>
#include <memory>

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class ConcreteCommand1 : public Command {
private:
    std::string argument;
public:
    ConcreteCommand1(const std::string& argument) : argument(argument) {}

    void execute() override {
        std::cout << "ConcreteCommand: execute(" << argument << ")\n";
    }
};

class ConcreteCommand2 : public Command {   
private:
    std::string argument;
public:
    ConcreteCommand2(const std::string& argument) : argument(argument) {}

    void execute() override {
        std::cout << "ConcreteCommand: execute(" << argument << ")\n";
    }
};

class Invoker {
private:
    std::shared_ptr<Command> command;
public:
    void setCommand(std::shared_ptr<Command> command) {
        this->command = command;
    }

    void executeCommand() {
        command->execute();
    }
};

int main() {
    Invoker invoker;
    invoker.setCommand(std::make_shared<ConcreteCommand1>("ARGUMENT"));
    invoker.executeCommand();

    return 0;
}

