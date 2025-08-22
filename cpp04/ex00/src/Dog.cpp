
#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << BLUE "🐶 A dog just appeared. Who's a gooood boyyyyy" RST << std::endl;
}

Dog::Dog(const Dog &d)
{
	this->type = d.type;
	std::cout << BLUE "🐶 A twin of our dog just appeared ! So cute." RST << std::endl;
}

Dog& Dog::operator=(const Dog &d)
{
	this->type = d.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << BLUE "🐶 The dog just left." RST << std::endl;
}

void	Dog::makeSound(void)
{
	std::cout << BLUE "🐶 WOOF WOOF (This is a dog sound)" RST << std::endl;
}
