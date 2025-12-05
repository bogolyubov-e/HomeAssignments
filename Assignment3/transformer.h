#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "weapon.h"
#include "vehicle.h"

class Transformer {
public:
  Transformer(const std::string& name, int health, const Weapon& weapon, Vehicle* vehicle);
  ~Transformer();
  
  std::string getName() const;
  int getHealth() const;
  Weapon getWeapon() const;
  Vehicle* getVehicle() const;
  
  void setName(const std::string& name);
  void setHealth(int health);
  void setWeapon(const Weapon& weapon);
  void setVehicle(Vehicle* vehicle);
  
  virtual bool transform();
  bool isAlive() const;
private:
  std::string name_;
  int health_;
  Weapon weapon_;
  Vehicle* vehicle_;
};

#endif
