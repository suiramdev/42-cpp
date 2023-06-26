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

    int getRawBits() const;
    void setRawBits(const int raw);
    float toFloat() const;
    int toInt() const;

    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
    bool operator>(const Fixed& fixed) const;
    bool operator<(const Fixed& fixed) const;
    bool operator>=(const Fixed& fixed) const;
    bool operator<=(const Fixed& fixed) const;
    bool operator==(const Fixed& fixed) const;
    bool operator!=(const Fixed& fixed) const;
    Fixed& operator+=(const Fixed& fixed);
    Fixed operator+(const Fixed& fixed) const;
    Fixed& operator-=(const Fixed& fixed);
    Fixed operator-(const Fixed& fixed) const;
    Fixed& operator*=(const Fixed& fixed);
    Fixed operator*(const Fixed& fixed) const;
    Fixed& operator/=(const Fixed& fixed);
    Fixed operator/(const Fixed& fixed) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};
