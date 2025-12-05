#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "transformer.h"
#include <string>

class Autobot : public Transformer {
public:
  Autobot(const std::string& name, int health, const Weapon& weapon, Vehicle* vehicle, int courage, bool hasShield);

  int getCourage() const;
  void setCourage(int courage);
  bool hasShield() const;
  void activateShield( bool activate);
  
  bool protectAlly();
  
  bool transform() override;

private:
  int courage_;
  bool shieldActive_;
};

#endif
