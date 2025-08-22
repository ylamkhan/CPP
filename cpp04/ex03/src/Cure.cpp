
#include "Cure.hpp"

Cure::Cure()
: AMateria("cure")
{
}

Cure::Cure(const Cure &src)
{
	_type = src._type;
}

Cure& Cure::operator=(const Cure &src)
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

Cure::~Cure()
{
}

Cure*	Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << PURP "* heals " GOLD << target.getName() << PURP "'s wounds *" RST << std::endl;
}
