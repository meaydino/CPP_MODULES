#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    _number = number << _fractionalBits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    _number = roundf(number * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _number = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (_number);
}

void Fixed::setRawBits(int const raw)
{
    _number = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_number) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_number >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
