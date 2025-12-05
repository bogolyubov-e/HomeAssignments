/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment3
*/

#include <gtest/gtest.h>
#include "../transformer.h"
#include "../weapon.h"
#include "../vehicle.h"

TEST(TransformerTest, BasicConstructor) {
    Weapon gun("Plasma Gun", 25);
    Vehicle truck("Truck", 120);
    
    Transformer t("Bumblebee", 100, gun, &truck);
    
    EXPECT_EQ(t.getName(), "Bumblebee");
    EXPECT_EQ(t.getHealth(), 100);
    EXPECT_EQ(t.getWeapon().getType(), "Plasma Gun");
    EXPECT_EQ(t.getVehicle()->getModel(), "Truck");
}

TEST(TransformerTest, Transform) {
    Weapon gun("Gun", 10);
    Vehicle car("Car", 150);
    
    Transformer withVehicle("WithCar", 100, gun, &car);
    Transformer withoutVehicle("NoCar", 100, gun, nullptr);
    
    EXPECT_TRUE(withVehicle.transform());
    EXPECT_FALSE(withoutVehicle.transform());
}

TEST(TransformerTest, IsAlive) {
    Weapon gun("Test", 1);
    Transformer t("Test", 100, gun, nullptr);
    
    EXPECT_TRUE(t.isAlive());
    t.setHealth(0);
    EXPECT_FALSE(t.isAlive());
}

