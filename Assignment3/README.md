# Assignment 4

## Author  
Bogolyubov Egor 25.581-MM

## Contacts  
st139974@student.spbu.ru

## Description  
Extension of the Transformers class hierarchy from Assignment 3 with full support for polymorphism.  
- Added pure virtual method and 2–3 virtual methods per class (each prints "ClassName::methodName()")  
- Implemented `operator<<` for stream output  
- Added constructor overloading (default + parametrized)  
- All methods and operators are thoroughly unit-tested using Google Test  
- Includes polymorphism test with vector of 9 objects (3 per derived class)

## Build  
make test_all

## Run Tests  
./transformer_tests

## Classes  
- Transformer (abstract base class)  
- Autobot, Decepticon, Maximal (concrete derived classes)  
- Weapon, Vehicle (component classes for composition and association)

## Testing  
- test_autobot.cpp  
- test_decepticon.cpp  
- test_maximal.cpp  
- test_weapon.cpp  
- test_vehicle.cpp  
- test_polymorphism.cpp (9-object vector test with virtual method calls via base pointer)
