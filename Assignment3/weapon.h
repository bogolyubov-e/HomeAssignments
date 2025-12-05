#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
  std::string type_;
  int damage_;
public:
  Weapon(const std::string& type, int damage);
  std::string getType() const;
  int getDamage() const;
  void setDamage(int damage);
};

#endif
