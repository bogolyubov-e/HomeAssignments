/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment3
*/

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "transformer.h"
#include <string>

class Decepticon : public Transformer {
public:
    Decepticon(const std::string& name, int health,
               const Weapon& weapon, Vehicle* vehicle,
               int evilLevel, bool canFly);
    
    int getEvilLevel() const;
    void setEvilLevel(int level);
    bool canFly() const;
    void setFlightAbility(bool canFly);
    
    bool terrorize();
    bool transform() override;

private:
    int evilLevel_;    // уровень злобы (1-100)
    bool flightCapable_; // умеет летать
};

#endif
