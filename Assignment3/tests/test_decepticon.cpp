/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#include <gtest/gtest.h>
#include "../decepticon.h"

TEST(DecepticonTest, DefaultConstructor)
{
    Decepticon d;
    EXPECT_EQ(d.getEvilLevel(), 0);
    EXPECT_FALSE(d.canFly());
}

TEST(DecepticonTest, Constructor)
{
    Weapon cannon("Ion Cannon", 35);
    Vehicle jet("Jet", 300);

    Decepticon megatron("Megatron", 120, cannon, &jet, 95, true);

    EXPECT_EQ(megatron.getName(), "Megatron");
    EXPECT_EQ(megatron.getEvilLevel(), 95);
    EXPECT_TRUE(megatron.canFly());
}

TEST(DecepticonTest, Terrorize)
{
    Weapon gun("Gun", 10);

    Decepticon evil("Evil", 100, gun, nullptr, 80, false);
    Decepticon notSoEvil("NotSoEvil", 100, gun, nullptr, 50, false);

    EXPECT_TRUE(evil.terrorize());
    EXPECT_FALSE(notSoEvil.terrorize());
}

TEST(DecepticonTest, FlightAbility)
{
    Weapon gun("Gun", 10);
    Decepticon flyer("Flyer", 100, gun, nullptr, 50, true);
    Decepticon walker("Walker", 100, gun, nullptr, 50, false);

    EXPECT_TRUE(flyer.canFly());
    EXPECT_FALSE(walker.canFly());

    walker.setFlightAbility(true);
    EXPECT_TRUE(walker.canFly());
}

TEST(DecepticonTest, TransformMethod)
{
    Weapon w("Cannon", 30);
    Decepticon d("Starscream", 150, w, nullptr, 85, true);
    d.transform();
}

TEST(DecepticonTest, ReportMethod)
{
    Decepticon d;
    d.report();
}

TEST(DecepticonTest, OutputStreamOperator)
{
    Weapon w("Laser", 20);
    Decepticon d("Megatron", 100, w, nullptr, 100, true);
    std::ostringstream oss;
    oss << d;
    std::string output = oss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("Megatron"), std::string::npos);
}

TEST(DecepticonTest, PolymorphicCallViaBasePointer)
{
    Weapon w("Gun", 10);
    std::unique_ptr<Transformer> t = std::make_unique<Decepticon>("TestDecepticon", 100, w, nullptr, 75, true);

    t->transform();
    t->report();
}
