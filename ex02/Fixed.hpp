#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
private:
    int _number;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed &operator=(const Fixed &other);
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed operator++(int);
    Fixed &operator++(void);
    Fixed operator--(int);
    Fixed &operator--(void);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);


    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat(void) const;
    int toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif


