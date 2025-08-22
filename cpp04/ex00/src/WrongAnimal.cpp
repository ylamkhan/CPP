
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
: type("Wrong type")
{
	std::cout << ORNG "A wild WrongAnimal has been created." RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	this->type = a.type;
	std::cout << ORNG "An WrongAnimal just clone itself." RST << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
	this->type = a.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << ORNG "A wild WrongAnimal has fled." RST << std::endl;
}

void	WrongAnimal::makeSound(void)
{
	std::cout << ORNG "* Unrecognized WrongAnimal sound *" RST << std::endl;
}
