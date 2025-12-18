/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment5
*/

#include "rational.h"
#include <cassert>

Rational::Rational(int num, int den) : num_(num), den_(den)
{
    if (den_ == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    normalize();
}

void Rational::normalize()
{
    if (den_ < 0)
    {
        num_ = -num_;
        den_ = -den_;
    }
    int g = std::gcd(num_ < 0 ? -num_ : num_, den_);
    if (g != 0)
    {
        num_ /= g;
        den_ /= g;
    }
}

Rational Rational::operator+(const Rational& other) const
{
    return Rational(num_ * other.den_ + other.num_ * den_, den_ * other.den_);
}

Rational Rational::operator-(const Rational& other) const
{
    return Rational(num_ * other.den_ - other.num_ * den_, den_ * other.den_);
}

Rational Rational::operator*(const Rational& other) const
{
    return Rational(num_ * other.num_, den_ * other.den_);
}

Rational Rational::operator/(const Rational& other) const
{
    if (other.num_ == 0)
    {
        throw std::invalid_argument("Division by zero");
    }
    return Rational(num_ * other.den_, den_ * other.num_);
}

bool Rational::operator==(const Rational& other) const
{
    return num_ == other.num_ && den_ == other.den_;
}

bool Rational::operator!=(const Rational& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
    os << r.num() << "/" << r.den();
    return os;
}
