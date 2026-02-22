/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#include "decepticon.h"
#include <iostream>

Decepticon::Decepticon()
    : Transformer(), evilLevel_(0), flightCapable_(false) {}

Decepticon::Decepticon(const std::string& name, int health,
                       const Weapon& weapon, Vehicle* vehicle,
                       int evilLevel, bool canFly)
    : Transformer(name, health, weapon, vehicle),
      evilLevel_(evilLevel), flightCapable_(canFly) {}

int Decepticon::getEvilLevel() const
{
    return evilLevel_;
}
void Decepticon::setEvilLevel(int level)
{
    evilLevel_ = level;
}

bool Decepticon::canFly() const
{
    return flightCapable_;
}
void Decepticon::setFlightAbility(bool canFly)
{
    flightCapable_ = canFly;
    std::cout << getName() << " flight ability: "
              << (canFly ? "enabled" : "disabled") << std::endl;
}

bool Decepticon::terrorize()
{
    if (evilLevel_ > 70)
    {
        std::cout << getName() << " causes terror and destruction!" << std::endl;
        return true;
    }
    std::cout << getName() << " is not evil enough to terrorize." << std::endl;
    return false;
}

void Decepticon::transform() const
{
    std::cout << "Decepticon::transform()" << std::endl;
}

void Decepticon::report() const
{
    std::cout << "Decepticon::report()" << std::endl;
}
