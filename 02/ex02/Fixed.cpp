#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value) : _value(value * (1 << _fractionalBits))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    _value = fixed._value;
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat() const
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _value / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& fixed) const
{
    return _value > fixed._value;
}

bool Fixed::operator<(const Fixed& fixed) const
{
    return _value < fixed._value;
}

bool Fixed::operator>=(const Fixed& fixed) const
{
    return _value >= fixed._value;
}

bool Fixed::operator<=(const Fixed& fixed) const
{
    return _value <= fixed._value;
}

bool Fixed::operator==(const Fixed& fixed) const
{
    return _value == fixed._value;
}

bool Fixed::operator!=(const Fixed& fixed) const
{
    return _value != fixed._value;
}

Fixed& Fixed::operator+=(const Fixed& fixed)
{
    _value += fixed._value;
    return *this;
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
    Fixed tmp(*this);
    tmp += fixed;
    return tmp;
}

Fixed& Fixed::operator-=(const Fixed& fixed)
{
    _value -= fixed._value;
    return *this;
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
    Fixed tmp(*this);
    tmp -= fixed;
    return tmp;
}

Fixed& Fixed::operator*=(const Fixed& fixed)
{
    _value = (_value * fixed._value) / (1 << _fractionalBits);
    return *this;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
    Fixed tmp(*this);
    tmp *= fixed;
    return tmp;
}

Fixed& Fixed::operator/=(const Fixed& fixed)
{
    _value /= fixed._value;
    return *this;
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
    Fixed tmp(*this);
    tmp /= fixed;
    return tmp;
}

Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return a > b ? a : b;
}
