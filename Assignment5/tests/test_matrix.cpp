#include <gtest/gtest.h>
#include "matrix.h"
#include "rational.h"

TEST(MatrixTest, ConstructionAndAccess)
{
    Matrix<int> m(2, 3, 5);
    EXPECT_EQ(m.rows(), 2);
    EXPECT_EQ(m.cols(), 3);
    EXPECT_EQ(m.at(1, 2), 5);
    m.at(0, 1) = 10;
    EXPECT_EQ(m.at(0, 1), 10);
}

TEST(MatrixTest, ScalarMultiplication)
{
    Matrix<double> m(2, 2, 1.0);
    Matrix<double> result = m * 3.0;
    EXPECT_DOUBLE_EQ(result.at(0, 0), 3.0);
}

TEST(MatrixTest, Addition)
{
    Matrix<int> a(2, 2, 1);
    Matrix<int> b(2, 2, 2);
    Matrix<int> c = a + b;
    EXPECT_EQ(c.at(1, 1), 3);
}

TEST(MatrixTest, MatrixMultiplication)
{
    Matrix<int> A(2, 3);
    A.at(0, 0) = 1;
    A.at(0, 1) = 2;
    A.at(0, 2) = 3;
    A.at(1, 0) = 4;
    A.at(1, 1) = 5;
    A.at(1, 2) = 6;

    Matrix<int> B(3, 2);
    B.at(0, 0) = 7;
    B.at(0, 1) = 8;
    B.at(1, 0) = 9;
    B.at(1, 1) = 10;
    B.at(2, 0) = 11;
    B.at(2, 1) = 12;

    Matrix<int> C = A * B;
    EXPECT_EQ(C.at(0, 0), 58);
    EXPECT_EQ(C.at(1, 1), 154);
}

TEST(MatrixTest, Transpose)
{
    Matrix<int> m(2, 3);
    m.at(0, 1) = 5;
    Matrix<int> t = m.transpose();
    EXPECT_EQ(t.rows(), 3);
    EXPECT_EQ(t.cols(), 2);
    EXPECT_EQ(t.at(1, 0), 5);
}

TEST(MatrixTest, WithRational)
{
    Matrix<Rational> m(2, 2);
    m.at(0, 0) = Rational(1, 2);
    m.at(0, 1) = Rational(3, 4);
    m.at(1, 0) = Rational(2, 3);
    m.at(1, 1) = Rational(5, 6);

    Matrix<Rational> t = m.transpose();
    EXPECT_EQ(t.at(0, 1), Rational(2, 3));
}
