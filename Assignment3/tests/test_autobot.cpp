#include <gtest/gtest.h>
#include "../autobot.h"

TEST(AutobotTest, Constructor) {
    Weapon shield("Energy Shield", 15);
    Vehicle truck("Truck", 100);
    
    Autobot optimus("Optimus", 150, shield, &truck, 95, true);
    
    EXPECT_EQ(optimus.getName(), "Optimus");
    EXPECT_EQ(optimus.getCourage(), 95);
    EXPECT_TRUE(optimus.hasShield());
}

TEST(AutobotTest, ProtectAlly) {
    Weapon gun("Gun", 10);
    Autobot brave("Brave", 100, gun, nullptr, 80, false);
    Autobot coward("Coward", 100, gun, nullptr, 30, false);
    
    EXPECT_TRUE(brave.protectAlly());
    EXPECT_FALSE(coward.protectAlly());
}

TEST(AutobotTest, ShieldActivation) {
    Weapon gun("Gun", 10);
    Autobot bot("Test", 100, gun, nullptr, 50, false);
    
    EXPECT_FALSE(bot.hasShield());
    bot.activateShield(true);
    EXPECT_TRUE(bot.hasShield());
    bot.activateShield(false);
    EXPECT_FALSE(bot.hasShield());
}

TEST(AutobotTest, TransformOverride) {
    Weapon gun("Gun", 10);
    Vehicle car("Car", 120);
    
    Autobot withVehicle("WithCar", 100, gun, &car, 60, false);
    Autobot withoutVehicle("NoCar", 100, gun, nullptr, 60, false);
    
    EXPECT_TRUE(withVehicle.transform());
    EXPECT_FALSE(withoutVehicle.transform());
}
