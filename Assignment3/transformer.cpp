/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#include <transformer.h>
#include <iostream>

Transformer::Transformer()
    : name_("Default"), health_(100), weapon_("None", 0), vehicle_(nullptr) {}
Transformer::Transformer(const std::string& name, int health, const Weapon& weapon, Vehicle* vehicle)
    : name_(name), health_(health), weapon_(weapon), vehicle_(vehicle) {}

std::string Transformer::getName() const
{
    return name_;
}
int Transformer::getHealth() const
{
    return health_;
}
Weapon Transformer::getWeapon() const
{
    return weapon_;
}
Vehicle* Transformer::getVehicle() const
{
    return vehicle_;
}

void Transformer::setName(const std::string& name)
{
    name_ = name;
}
void Transformer::setHealth(int health)
{
    health_ = health;
}
void Transformer::setWeapon(const Weapon& weapon)
{
    weapon_ = weapon;
}
void Transformer::setVehicle(Vehicle* vehicle)
{
    vehicle_ = vehicle;
}

void Transformer::report() const
{
    std::cout << "Transformer::report()" << std::endl;
}

bool Transformer::isAlive() const
{
    return health_ > 0;
}

std::ostream& operator<<(std::ostream& os, const Transformer& t)
{
    os << "Transformer name - " << t.getName();
    return os;
}
