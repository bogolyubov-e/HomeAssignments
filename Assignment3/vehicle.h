/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment3
*/

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
  std::string model_;
  int max_speed_;
public:
  Vehicle(const std::string& model, int max_speed);
  std::string getModel() const;
  int getMaxSpeed() const;
};

#endif
