
#include "Dog.hpp"

Dog::Dog(void) : Animal(), brain(new Brain())
{
	this->type = "Dog";
	std::cout << BLUE "🐶 A dog just appeared. Who's a gooood boyyyyy" RST << std::endl;
}

Dog::Dog(const Dog &d) : Animal(), brain(NULL)
{
	*this = d;
	std::cout << BLUE "🐶 A twin of our dog just appeared ! They're cute." RST << std::endl;
}

Dog& Dog::operator=(const Dog &d)
{
	if (this != &d)
	{
		this->type = d.type;
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*d.brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << BLUE "🐶 The dog just left. Mayeb he'll bring back the ball." RST << std::endl;
	delete this->brain;
}

void	Dog::makeSound(void)
{
	std::cout << BLUE "🐶 WOOF WOOF (This is a dog sound)" RST << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->brain);
}
