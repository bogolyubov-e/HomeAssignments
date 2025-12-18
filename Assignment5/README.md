# Assignment 5

## Author  
Bogolyubov Egor 25.581-MM

## Contacts  
st139974@student.spbu.ru

## Description  
Template-based matrix class supporting:
- Scalar multiplication
- Matrix addition
- Matrix-matrix multiplication
- Transpose
- Full compatibility with built-in types (`int`, `double`) and custom `Rational` class

The `Rational` class maintains invariants:
- Denominator > 0
- GCD(|numerator|, denominator) = 1
- Denominator ≠ 0

All operations are thoroughly tested with Google Test.

## Build  
make test

## Run Tests  
./matrix_tests

## Classes  
- `Rational` — immutable rational number with normalized form  
- `Matrix<T>` — template matrix class with dynamic dimensions

## Testing  
- `test_rational.cpp` — covers construction, arithmetic, invariants  
- `test_matrix.cpp` — covers all matrix operations with `int`, `double`, and `Rational`
