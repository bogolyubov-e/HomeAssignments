/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include "weapon.h"
#include "vehicle.h"

class Transformer
{
public:
    Transformer();
    Transformer(const std::string& name, int health, const Weapon& weapon, Vehicle* vehicle);
    virtual ~Transformer() = default;

    std::string getName() const;
    int getHealth() const;
    Weapon getWeapon() const;
    Vehicle* getVehicle() const;

    void setName(const std::string& name);
    void setHealth(int health);
    void setWeapon(const Weapon& weapon);
    void setVehicle(Vehicle* vehicle);

    virtual void transform() const = 0;
    virtual void report() const;
    bool isAlive() const;

    friend std::ostream& operator<<(std::ostream& os, const Transformer& t);
private:
    std::string name_;
    int health_;
    Weapon weapon_;
    Vehicle* vehicle_;
};

#endif
