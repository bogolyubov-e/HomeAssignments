/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment3
*/

#include <gtest/gtest.h>
#include "../maximal.h"

TEST(MaximalTest, Constructor) {
    Weapon claws("Energy Claws", 20);
    Vehicle car("Car", 180);
    
    Maximal cheetor("Cheetor", 90, claws, &car, "Cheetah", 85);
    
    EXPECT_EQ(cheetor.getName(), "Cheetor");
    EXPECT_EQ(cheetor.getBeastMode(), "Cheetah");
    EXPECT_EQ(cheetor.getAgility(), 85);
}

TEST(MaximalTest, BeastPower) {
    Weapon gun("Gun", 10);
    
    Maximal withBeast("WithBeast", 100, gun, nullptr, "Tiger", 70);
    Maximal withoutBeast("NoBeast", 100, gun, nullptr, "", 50);
    
    EXPECT_TRUE(withBeast.useBeastPower());
    EXPECT_FALSE(withoutBeast.useBeastPower());
}

TEST(MaximalTest, TransformOverride) {
    Weapon gun("Gun", 10);
    Vehicle vehicle("Vehicle", 100);
    
    Maximal withBeast("Beast", 100, gun, &vehicle, "Wolf", 70);
    Maximal withoutBeast("NoBeast", 100, gun, &vehicle, "", 50);
    Maximal noVehicle("Nothing", 100, gun, nullptr, "", 50);
    
    EXPECT_TRUE(withBeast.transform());    // В животное
    EXPECT_TRUE(withoutBeast.transform()); // В транспорт
    EXPECT_FALSE(noVehicle.transform());   // Ни во что
}

TEST(MaximalTest, SetBeastMode) {
    Weapon gun("Gun", 10);
    Maximal beast("Beast", 100, gun, nullptr, "Bear", 60);
    
    EXPECT_EQ(beast.getBeastMode(), "Bear");
    beast.setBeastMode("Eagle");
    EXPECT_EQ(beast.getBeastMode(), "Eagle");
}

