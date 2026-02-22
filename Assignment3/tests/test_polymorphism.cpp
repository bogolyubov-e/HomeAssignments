/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment4
*/

#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include "../autobot.h"
#include "../decepticon.h"
#include "../maximal.h"

TEST(PolymorphismTest, VectorOfTransformers)
{
    std::vector<std::unique_ptr<Transformer>> bots;

    Weapon w1("Blaster", 15);
    Weapon w2("Cannon", 20);
    Weapon w3("Laser", 25);

    // 3 Autobots
    bots.push_back(std::make_unique<Autobot>("Optimus", 150, w1, nullptr, 90, true));
    bots.push_back(std::make_unique<Autobot>("Bumblebee", 100, w2, nullptr, 60, false));
    bots.push_back(std::make_unique<Autobot>("Jazz", 120, w3, nullptr, 75, true));

    // 3 Decepticons
    bots.push_back(std::make_unique<Decepticon>("Megatron", 200, w1, nullptr, 95, true));
    bots.push_back(std::make_unique<Decepticon>("Starscream", 130, w2, nullptr, 80, false));
    bots.push_back(std::make_unique<Decepticon>("Shockwave", 180, w3, nullptr, 90, true));

    // 3 Maximals
    bots.push_back(std::make_unique<Maximal>("Optimal Optimus", 160, w1, nullptr, "Wolf", 85));
    bots.push_back(std::make_unique<Maximal>("Cheetor", 110, w2, nullptr, "Cheetah", 95));
    bots.push_back(std::make_unique<Maximal>("Rhinox", 140, w3, nullptr, "Rhino", 70));

    // Вызов виртуальных методов для всех объектов
    for (const auto& bot : bots)
    {
        bot->transform();  // → каждый печатает свой "ClassName::transform()"
        bot->report();     // → каждый печатает свой "ClassName::report()"
    }

    // Проверка: все объекты живы (не упали из-за UB)
    EXPECT_EQ(bots.size(), 9u);
}
