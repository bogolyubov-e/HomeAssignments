/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#include <gtest/gtest.h>
#include "../weapon.h"

TEST(WeaponTest, Constructor)
{
    Weapon w("Plasma Rifle", 35);

    EXPECT_EQ(w.getType(), "Plasma Rifle");
    EXPECT_EQ(w.getDamage(), 35);
}

TEST(WeaponTest, SetDamage)
{
    Weapon w("Test", 10);

    w.setDamage(50);
    EXPECT_EQ(w.getDamage(), 50);

    w.setDamage(0);
    EXPECT_EQ(w.getDamage(), 0);

    w.setDamage(-10);
    EXPECT_EQ(w.getDamage(), -10); // Допустимо по логике
}

TEST(WeaponTest, DifferentWeapons)
{
    Weapon rifle("Rifle", 25);
    Weapon cannon("Cannon", 50);
    Weapon sword("Sword", 15);

    EXPECT_EQ(rifle.getType(), "Rifle");
    EXPECT_EQ(cannon.getDamage(), 50);
    EXPECT_EQ(sword.getType(), "Sword");
}

