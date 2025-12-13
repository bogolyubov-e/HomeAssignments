/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#ifndef MAXIMAL_H
#define MAXIMAL_H

#include "transformer.h"
#include <string>

class Maximal : public Transformer
{
public:
    Maximal();
    Maximal(const std::string& name, int health,
            const Weapon& weapon, Vehicle* vehicle,
            const std::string& beastMode, int agility);

    std::string getBeastMode() const;
    void setBeastMode(const std::string& beast);
    int getAgility() const;
    void setAgility(int agility);

    bool useBeastPower();
    void transform() const override;
    void report() const override;
private:
    std::string beastMode_;
    int agility_;
};

#endif
