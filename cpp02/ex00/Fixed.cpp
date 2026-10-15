#include "Fixed.hpp"
#include<iostream>

Fixed::Fixed(): _number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    _number = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        _number = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(_number);
}

void Fixed::setRawBits(int const raw)
{
    _number = raw;
}

Fixed::~Fixed()
{
    std::cout<< "Destructor called" << std::endl;
}
