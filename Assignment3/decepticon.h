/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "transformer.h"
#include <string>

class Decepticon : public Transformer
{
public:
    Decepticon();
    Decepticon(const std::string& name, int health,
               const Weapon& weapon, Vehicle* vehicle,
               int evilLevel, bool canFly);

    int getEvilLevel() const;
    void setEvilLevel(int level);
    bool canFly() const;
    void setFlightAbility(bool canFly);

    bool terrorize();
    void transform() const override;
    void report() const override;
private:
    int evilLevel_;
    bool flightCapable_;
};

#endif
