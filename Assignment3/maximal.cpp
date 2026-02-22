/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#include "maximal.h"
#include <iostream>

Maximal::Maximal()
    : Transformer(), beastMode_("None"), agility_(0) {}

Maximal::Maximal(const std::string& name, int health,
                 const Weapon& weapon, Vehicle* vehicle,
                 const std::string& beastMode, int agility)
    : Transformer(name, health, weapon, vehicle),
      beastMode_(beastMode), agility_(agility) {}

std::string Maximal::getBeastMode() const
{
    return beastMode_;
}
void Maximal::setBeastMode(const std::string& beast)
{
    beastMode_ = beast;
    std::cout << getName() << " now transforms into a " << beast << std::endl;
}

int Maximal::getAgility() const
{
    return agility_;
}
void Maximal::setAgility(int agility)
{
    agility_ = agility;
}

bool Maximal::useBeastPower()
{
    if (!beastMode_.empty())
    {
        std::cout << getName() << " uses " << beastMode_
                  << " powers with agility " << agility_ << "!" << std::endl;
        return true;
    }
    std::cout << getName() << " has no beast mode activated." << std::endl;
    return false;
}

void Maximal::transform() const
{
    std::cout << "Maximal::transform()" << std::endl;
}

void Maximal::report() const
{
    std::cout << "Maximal::report()" << std::endl;
}
