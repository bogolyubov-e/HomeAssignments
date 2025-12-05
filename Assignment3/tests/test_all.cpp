#include <gtest/gtest.h>

// Подключаем все тестовые наборы
#include "test_transformer.cpp"
#include "test_weapon.cpp"
#include "test_vehicle.cpp"
#include "test_autobot.cpp"
#include "test_decepticon.cpp"
#include "test_maximal.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
