/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/


#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "transformer.h"
#include <string>

class Autobot : public Transformer
{
public:
    Autobot();
    Autobot(const std::string& name, int health, const Weapon& weapon, Vehicle* vehicle, int courage, bool hasShield);

    int getCourage() const;
    void setCourage(int courage);
    bool hasShield() const;
    void activateShield( bool activate);

    bool protectAlly();

    void transform() const override;
    void report() const override;
private:
    int courage_;
    bool shieldActive_;
};

#endif
