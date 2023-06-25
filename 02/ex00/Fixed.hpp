#pragma once

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& fixed);
    ~Fixed();

    Fixed& operator=(const Fixed& fixed);

    int getRawBits() const;
    void setRawBits(const int raw);
};
