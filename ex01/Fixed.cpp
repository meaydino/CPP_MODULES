#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Default constructor
Fixed::Fixed(): _number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Integer constructor
Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    _number = number << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    _number = roundf(number * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _number = other.getRawBits();
    return (*this);
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Get raw bits
int Fixed::getRawBits(void) const
{
    return (_number);
}

// Set raw bits
void Fixed::setRawBits(int const raw)
{
    _number = raw;
}

// Convert to float
float Fixed::toFloat(void) const
{
    return (static_cast<float>(_number) / (1 << _fractionalBits));
}

// Convert to int
int Fixed::toInt(void) const
{
    return (_number >> _fractionalBits);
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}