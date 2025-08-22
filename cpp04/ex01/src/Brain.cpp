

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << SALM "🧠 Brain default constructor called." RST << std::endl;
}

Brain::Brain(const Brain &b)
{
	std::cout << SALM "🧠 Brain copy constructor called." RST << std::endl;
	*this = b;
}

Brain& Brain::operator=(const Brain &b)
{
	for (int i = 0; i < this->nbIdeas; i++)
		this->ideas[i] = b.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << SALM "🧠 Brain default destructor called." RST << std::endl;
}

void Brain::setIdea(int index, const std::string idea)
{
	if (index >= 0 && index < this->nbIdeas)
		this->ideas[index] = idea;
	else
		std::cout << REDD "Not valid index to set idea." RST << std::endl;
}

std::string Brain::getIdea(int index)
{
	if (index >= 0 && index < this->nbIdeas)
		return (this->ideas[index]);
	else
		std::cout << REDD "Not valid index to set idea." RST << std::endl;
	return ("");
}
