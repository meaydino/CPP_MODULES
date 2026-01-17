class Fixed
{
private:
    int _number;
    static const int _number_storage = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed& other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    ~Fixed();

};

