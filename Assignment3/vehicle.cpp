/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment3
*/

#include <vehicle.h>

Vehicle::Vehicle(const std::string& model, int max_speed)
  : model_(model), max_speed_(max_speed) {}
  
std::string Vehicle::getModel() const { return model_; }
int Vehicle::getMaxSpeed() const { return max_speed_; }
