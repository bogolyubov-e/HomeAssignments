#include <gtest/gtest.h>
#include "../decepticon.h"

TEST(DecepticonTest, Constructor) {
    Weapon cannon("Ion Cannon", 35);
    Vehicle jet("Jet", 300);
    
    Decepticon megatron("Megatron", 120, cannon, &jet, 95, true);
    
    EXPECT_EQ(megatron.getName(), "Megatron");
    EXPECT_EQ(megatron.getEvilLevel(), 95);
    EXPECT_TRUE(megatron.canFly());
}

TEST(DecepticonTest, Terrorize) {
    Weapon gun("Gun", 10);
    
    Decepticon evil("Evil", 100, gun, nullptr, 80, false);
    Decepticon notSoEvil("NotSoEvil", 100, gun, nullptr, 50, false);
    
    EXPECT_TRUE(evil.terrorize());
    EXPECT_FALSE(notSoEvil.terrorize());
}

TEST(DecepticonTest, FlightAbility) {
    Weapon gun("Gun", 10);
    Decepticon flyer("Flyer", 100, gun, nullptr, 50, true);
    Decepticon walker("Walker", 100, gun, nullptr, 50, false);
    
    EXPECT_TRUE(flyer.canFly());
    EXPECT_FALSE(walker.canFly());
    
    walker.setFlightAbility(true);
    EXPECT_TRUE(walker.canFly());
}

TEST(DecepticonTest, TransformOverride) {
    Weapon gun("Gun", 10);
    Vehicle tank("Tank", 60);
    
    Decepticon withVehicle("WithTank", 100, gun, &tank, 70, false);
    Decepticon withoutVehicle("NoVehicle", 100, gun, nullptr, 70, false);
    
    EXPECT_TRUE(withVehicle.transform());
    EXPECT_FALSE(withoutVehicle.transform());
}

