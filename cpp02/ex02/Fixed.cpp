#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _number(0)
{
}

Fixed::Fixed(const int number)
{
    _number = number << _fractionalBits;
}

Fixed::Fixed(const float number)
{
    _number = roundf(number * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _number = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
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

bool Fixed::operator>(const Fixed& other) const
{
    return(this->_number > other._number);

}
bool Fixed::operator<(const Fixed& other) const
{
    return(this->_number < other._number);
}
bool Fixed::operator>=(const Fixed& other) const
{
    return(this->_number >= other._number);
}
bool Fixed::operator<=(const Fixed& other) const
{
    return(this->_number <= other._number);
}
bool Fixed::operator==(const Fixed& other) const
{
    return(this->_number == other._number);
}
bool Fixed::operator!=(const Fixed& other) const
{
    return(this->_number != other._number);
}
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_number + other._number);
    return(result);
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_number - other._number);
    return(result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    long tmp = (long)this->_number * (long)other._number;
    tmp = tmp >> _fractionalBits;
    result.setRawBits((int)tmp);
    return(result);
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    long tmp = ((long)this->_number << _fractionalBits) / other._number;
    result.setRawBits((int)tmp);
    return(result);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_number++;
    return(tmp);
}
Fixed &Fixed::operator++(void)
{
    this->_number++;
    return(*this);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_number--;
    return(tmp);
}
Fixed &Fixed::operator--(void)
{
    this->_number--;
    return(*this);
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}


