#include <weapon.h>

Weapon::Weapon(const std::string& type, int damage)
	: type_(type), damage_(damage) {}
	
std::string Weapon::getType() const { return type_;}
int Weapon::getDamage() const { return damage_; }
void Weapon::setDamage(int damage) { damage_ = damage; }
