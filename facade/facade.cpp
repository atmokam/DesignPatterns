#include <memory>
#include <iostream>
#include <string>

class CPU {
public:
    void freeze() { std::cout << "CPU freeze\n"; }
    void jump(long position) { std::cout << "CPU jump to " << position << "\n"; }
    void execute() { std::cout << "CPU execute\n"; }
};

class Memory {
public:
    void load(long position, std::string data) { 
        std::cout << "Memory load from " << position << " data: " << data << "\n"; 
    }
};

class HardDrive {
public:
    std::string read(long lba, int size) { 
        return "HardDrive read lba " + std::to_string(lba) + " size " + std::to_string(size) + "\n"; 
    }
};

class ComputerFacade {
private:
    std::shared_ptr<CPU> cpu;
    std::shared_ptr<Memory> memory;
    std::shared_ptr<HardDrive> hardDrive;

public:
    ComputerFacade() : cpu(std::make_shared<CPU>()), 
                       memory(std::make_shared<Memory>()), 
                       hardDrive(std::make_shared<HardDrive>()) {}

    void start() {
        cpu->freeze();
        memory->load(BOOT_ADDRESS, hardDrive->read(BOOT_SECTOR, SECTOR_SIZE));
        cpu->jump(BOOT_ADDRESS);
        cpu->execute();
    }

private:
    static constexpr long BOOT_ADDRESS = 0;
    static constexpr long BOOT_SECTOR = 0;
    static constexpr int SECTOR_SIZE = 1024;
};
