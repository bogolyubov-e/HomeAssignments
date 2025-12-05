#include <gtest/gtest.h>
#include "../vehicle.h"

TEST(VehicleTest, ConstructorAndGetters) {
    Vehicle car("Sports Car", 250);
    
    EXPECT_EQ(car.getModel(), "Sports Car");
    EXPECT_EQ(car.getMaxSpeed(), 250);
}

TEST(VehicleTest, DifferentVehicles) {
    Vehicle truck("Truck", 120);
    Vehicle jet("Jet", 800);
    Vehicle bike("Motorcycle", 180);
    
    EXPECT_EQ(truck.getModel(), "Truck");
    EXPECT_EQ(jet.getMaxSpeed(), 800);
    EXPECT_EQ(bike.getModel(), "Motorcycle");
}

TEST(VehicleTest, SpeedBoundaries) {
    Vehicle slow("Turtle", 5);
    Vehicle fast("Rocket", 1000);
    Vehicle zero("Broken", 0);
    
    EXPECT_EQ(slow.getMaxSpeed(), 5);
    EXPECT_EQ(fast.getMaxSpeed(), 1000);
    EXPECT_EQ(zero.getMaxSpeed(), 0);
}

