/*
 Egor Bogolyubov
 student139974@student.spbu.ru
 HomeAssignment5
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept>
#include <numeric>

class Rational
{
public:
    Rational(int num = 0, int den = 1);

    int num() const
    {
        return num_;
    }
    int den() const
    {
        return den_;
    }

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

private:
    int num_;
    int den_;

    void normalize();
};

std::ostream& operator<<(std::ostream& os, const Rational& r);

#endif
