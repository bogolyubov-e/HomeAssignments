#include "autobot.h"
#include <iostream>

Autobot::Autobot(const std::string& name, int health, 
                 const Weapon& weapon, Vehicle* vehicle,
                 int courage, bool hasShield)
    : Transformer(name, health, weapon, vehicle),
      courage_(courage), shieldActive_(hasShield) {}

int Autobot::getCourage() const { return courage_; }
void Autobot::setCourage(int courage) { courage_ = courage; }

bool Autobot::hasShield() const { return shieldActive_; }
void Autobot::activateShield(bool activate) { 
    shieldActive_ = activate; 
    std::cout << getName() << " shield " 
              << (activate ? "activated" : "deactivated") << std::endl;
}

bool Autobot::protectAlly() {
    if (courage_ > 50) {
        std::cout << getName() << " bravely protects an ally!" << std::endl;
        return true;
    }
    std::cout << getName() << " is too scared to protect others." << std::endl;
    return false;
}

bool Autobot::transform() {
    if (getVehicle() != nullptr) {
        std::cout << getName() << " transforms into a heroic vehicle!" << std::endl;
        return true;
    }
    return false;
}
