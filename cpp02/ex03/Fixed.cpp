
#include <iostream>
#include <cmath>

#include "Fixed.hpp"

int Fixed::_fract = 8;

Fixed::Fixed(): _value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const n) {
	// std::cout << "Int constructor called" << std::endl;
	_value = n << _fract;
}

Fixed::Fixed(float const n) {
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(n * (1 << _fract));
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &other) {
	// std::cout << "Assignation operator called" << std::endl;
	if (this != &other) {
		_value = other.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float)_value / (float)(1 << _fract);
}

int	Fixed::toInt(void) const {
	return (int)(_value >> _fract);
}

bool	Fixed::operator>(Fixed const &other) const {
	return getRawBits() > other.getRawBits();
}

bool	Fixed::operator<(Fixed const &other) const {
	return getRawBits() < other.getRawBits();
}

bool	Fixed::operator>=(Fixed const &other) const {
	return getRawBits() >= other.getRawBits();
}

bool	Fixed::operator<=(Fixed const &other) const {
	return getRawBits() <= other.getRawBits();
}

bool	Fixed::operator==(Fixed const &other) const {
	return getRawBits() == other.getRawBits();
}

bool	Fixed::operator!=(Fixed const &other) const {
	return getRawBits() != other.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &other) const {
	Fixed	ret;
	ret.setRawBits(getRawBits() + other.getRawBits());
	return ret;
}

Fixed	Fixed::operator-(Fixed const &other) const {
	Fixed	ret;
	ret.setRawBits(getRawBits() - other.getRawBits());
	return ret;
}

Fixed	Fixed::operator*(Fixed const &other) const {
	Fixed	ret;
	ret.setRawBits(getRawBits() * other.getRawBits() >> _fract);
	return ret;
}

Fixed	Fixed::operator/(Fixed const &other) const {
	Fixed	ret;
	ret.setRawBits(getRawBits() / other.getRawBits() << _fract);
	return ret;
}

Fixed&	Fixed::operator++() {
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	operator++();
	return tmp;
}

Fixed&	Fixed::operator--() {
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	operator--();
	return tmp;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return a < b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return a > b ? a : b;
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}

Fixed const &min(Fixed const &a, Fixed const &b) {
	return Fixed::min(a, b);
}

Fixed const &max(Fixed const &a, Fixed const &b) {
	return Fixed::max(a, b);
}
