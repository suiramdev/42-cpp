#pragma once

#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    Fixed& operator=(const Fixed& fixed);
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

    int getRawBits() const;
    void setRawBits(const int raw);
    float toFloat() const;
    int toInt() const;
};
