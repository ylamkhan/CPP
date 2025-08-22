
#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::~Point() {}

Point::Point(Point const &other) {
	*this = other;
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y) {}

Point&	Point::operator=(Point const &other) {
	(void)other;
	return *this;
}

Fixed const &Point::getX(void) const {
	return _x;
}

Fixed const &Point::getY(void) const {
	return _y;
}
