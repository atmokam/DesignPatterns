#include <iostream>
#include <memory>


class Notifier {
public:
    Notifier(int priority) : priority(priority), nextNotifier(nullptr) {}

    void setNextNotifier(std::shared_ptr<Notifier> nextNotifier){
        this->nextNotifier = nextNotifier;
    }

    void notify(int level, const std::string& message){
        if(level >= priority){
            write(message);
        }
        if(nextNotifier != nullptr){
            nextNotifier->notify(level, message);
        }
    }

protected:
    virtual void write(const std::string& message) = 0;

private:
    int priority;
    std::shared_ptr<Notifier> nextNotifier;
};


class EmailNotifier : public Notifier {
public:
    EmailNotifier(int priority) : Notifier(priority) {}

protected:
    void write(const std::string& message) override {
        std::cout << "Sending email notification: " << message << std::endl;
    }
};

class SMSNotifier : public Notifier {
public:
    SMSNotifier(int priority) : Notifier(priority) {}

protected:
    void write(const std::string& message) override {
        std::cout << "Sending SMS notification: " << message << std::endl;
    }
};

class PushNotifier : public Notifier {
public:
    PushNotifier(int priority) : Notifier(priority) {}

protected:
    void write(const std::string& message) override {
        std::cout << "Sending Push notification: " << message << std::endl;
    }
};

int main() {
    auto emailNotifier = std::make_shared<EmailNotifier>(1);
    auto smsNotifier = std::make_shared<SMSNotifier>(2);
    auto pushNotifier = std::make_shared<PushNotifier>(3);

    emailNotifier->setNextNotifier(smsNotifier);
    smsNotifier->setNextNotifier(pushNotifier);

    emailNotifier->notify(2, "Youve got a message!");

    return 0;
}