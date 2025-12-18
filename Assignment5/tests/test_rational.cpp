#include <gtest/gtest.h>
#include "rational.h"

TEST(RationalTest, ConstructorAndNormalization)
{
    Rational r1(2, 4);
    EXPECT_EQ(r1.num(), 1);
    EXPECT_EQ(r1.den(), 2);

    Rational r2(-3, -6);
    EXPECT_EQ(r2.num(), 1);
    EXPECT_EQ(r2.den(), 2);

    Rational r3(0, 5);
    EXPECT_EQ(r3.num(), 0);
    EXPECT_EQ(r3.den(), 1);
}

TEST(RationalTest, Arithmetic)
{
    Rational a(1, 2);
    Rational b(1, 3);

    EXPECT_EQ(a + b, Rational(5, 6));
    EXPECT_EQ(a - b, Rational(1, 6));
    EXPECT_EQ(a * b, Rational(1, 6));
    EXPECT_EQ(a / b, Rational(3, 2));
}

TEST(RationalTest, Equality)
{
    Rational x(2, 4);
    Rational y(1, 2);
    EXPECT_EQ(x, y);
    EXPECT_NE(x, Rational(1, 3));
}

TEST(RationalTest, DivisionByZero)
{
    Rational a(1, 2);
    Rational b(0, 1);
    EXPECT_THROW(a / b, std::invalid_argument);
}
