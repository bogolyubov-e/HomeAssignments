#include <transformer.h>
#include <iostream>

Transformer::Transformer(const std::string& name, int health, const Weapon& weapon, Vehicle* vehicle)
  : name_(name), health_(health), weapon_(weapon), vehicle_(vehicle) {}

Transformer::~Transformer() {

}

std::string Transformer::getName() const {return name_; }
int Transformer::getHealth() const {return health_; }
Weapon Transformer::getWeapon() const {return weapon_; }
Vehicle* Transformer::getVehicle() const {return vehicle_; }

void Transformer::setName(const std::string& name) { name_ = name; }
void Transformer::setHealth(int health) { health_ = health; }
void Transformer::setWeapon(const Weapon& weapon) { weapon_ = weapon; }
void Transformer::setVehicle(Vehicle* vehilce) { vehicle_ = vehilce; }

bool Transformer::transform() {
  return vehicle_ != nullptr;
}

bool Transformer::isAlive() const {
  return health_ > 0;
}
