/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#include <gtest/gtest.h>
#include "../maximal.h"

TEST(MaximalTest, DefaultConstructor)
{
    Maximal m;
    EXPECT_EQ(m.getBeastMode(), "None");
    EXPECT_EQ(m.getAgility(), 0);
}

TEST(MaximalTest, Constructor)
{
    Weapon claws("Energy Claws", 20);
    Vehicle car("Car", 180);

    Maximal cheetor("Cheetor", 90, claws, &car, "Cheetah", 85);

    EXPECT_EQ(cheetor.getName(), "Cheetor");
    EXPECT_EQ(cheetor.getBeastMode(), "Cheetah");
    EXPECT_EQ(cheetor.getAgility(), 85);
}

TEST(MaximalTest, BeastPower)
{
    Weapon gun("Gun", 10);

    Maximal withBeast("WithBeast", 100, gun, nullptr, "Tiger", 70);
    Maximal withoutBeast("NoBeast", 100, gun, nullptr, "", 50);

    EXPECT_TRUE(withBeast.useBeastPower());
    EXPECT_FALSE(withoutBeast.useBeastPower());
}

TEST(MaximalTest, SetBeastMode)
{
    Weapon gun("Gun", 10);
    Maximal beast("Beast", 100, gun, nullptr, "Bear", 60);

    EXPECT_EQ(beast.getBeastMode(), "Bear");
    beast.setBeastMode("Eagle");
    EXPECT_EQ(beast.getBeastMode(), "Eagle");
}

TEST(MaximalTest, TransformMethod)
{
    Weapon w("Blade", 25);
    Maximal m("Rattrap", 120, w, nullptr, "Rat", 85);
    m.transform(); // → "Maximal::transform()"
}

TEST(MaximalTest, ReportMethod)
{
    Maximal m;
    m.report(); // → "Maximal::report()"
}

TEST(MaximalTest, OutputStreamOperator)
{
    Weapon w("Claw", 22);
    Maximal m("Dinobot", 150, w, nullptr, "Tyrannosaurus", 90);
    std::ostringstream oss;
    oss << m;
    std::string output = oss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("Dinobot"), std::string::npos);
}

TEST(MaximalTest, PolymorphicCallViaBasePointer)
{
    Weapon w("Fang", 15);
    std::unique_ptr<Transformer> t = std::make_unique<Maximal>("TestMaximal", 100, w, nullptr, "Lion", 88);

    t->transform();  // → "Maximal::transform()"
    t->report();     // → "Maximal::report()"
}
