/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#include <gtest/gtest.h>
#include "../autobot.h"

TEST(AutobotTest, Constructor)
{
    Weapon shield("Energy Shield", 15);
    Vehicle truck("Truck", 100);

    Autobot optimus("Optimus", 150, shield, &truck, 95, true);

    EXPECT_EQ(optimus.getName(), "Optimus");
    EXPECT_EQ(optimus.getCourage(), 95);
    EXPECT_TRUE(optimus.hasShield());
}

TEST(AutobotTest, ProtectAlly)
{
    Weapon gun("Gun", 10);
    Autobot brave("Brave", 100, gun, nullptr, 80, false);
    Autobot coward("Coward", 100, gun, nullptr, 30, false);

    EXPECT_TRUE(brave.protectAlly());
    EXPECT_FALSE(coward.protectAlly());
}

TEST(AutobotTest, ShieldActivation)
{
    Weapon gun("Gun", 10);
    Autobot bot("Test", 100, gun, nullptr, 50, false);

    EXPECT_FALSE(bot.hasShield());
    bot.activateShield(true);
    EXPECT_TRUE(bot.hasShield());
    bot.activateShield(false);
    EXPECT_FALSE(bot.hasShield());
}

TEST(AutobotTest, DefaultConstructor)
{
    Autobot a;
    EXPECT_EQ(a.getCourage(), 0);
}

TEST(AutobotTest, TransformMethod)
{
    Weapon w("Blaster", 10);
    Autobot a("Test", 100, w, nullptr, 50, false);
    a.transform();
}

TEST(AutobotTest, ReportMethod)
{
    Autobot a;
    a.report();
}

TEST(AutobotTest, OutputStreamOperator)
{
    Weapon w("Blaster", 20);
    Autobot a("Optimus", 100, w, nullptr, 80, true);
    std::ostringstream oss;
    oss << a;
    std::string output = oss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("Optimus"), std::string::npos);
}

TEST(AutobotTest, PolymorphicCallViaBasePointer)
{
    Weapon w("Gun", 10);
    Transformer* t = new Autobot("Polymorph", 100, w, nullptr, 60, false);

    t->transform();
    t->report();

    delete t;
}
