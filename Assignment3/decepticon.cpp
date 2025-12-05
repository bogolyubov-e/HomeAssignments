#include "decepticon.h"
#include <iostream>

Decepticon::Decepticon(const std::string& name, int health,
                       const Weapon& weapon, Vehicle* vehicle,
                       int evilLevel, bool canFly)
    : Transformer(name, health, weapon, vehicle),
      evilLevel_(evilLevel), flightCapable_(canFly) {}

int Decepticon::getEvilLevel() const { return evilLevel_; }
void Decepticon::setEvilLevel(int level) { evilLevel_ = level; }

bool Decepticon::canFly() const { return flightCapable_; }
void Decepticon::setFlightAbility(bool canFly) { 
    flightCapable_ = canFly; 
    std::cout << getName() << " flight ability: " 
              << (canFly ? "enabled" : "disabled") << std::endl;
}

bool Decepticon::terrorize() {
    if (evilLevel_ > 70) {
        std::cout << getName() << " causes terror and destruction!" << std::endl;
        return true;
    }
    std::cout << getName() << " is not evil enough to terrorize." << std::endl;
    return false;
}

bool Decepticon::transform() {
    if (getVehicle() != nullptr) {
        std::cout << getName() << " transforms into a sinister vehicle!" << std::endl;
        return true;
    }
    return false;
}
