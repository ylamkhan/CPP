

#pragma once

#include "AMateria.hpp"

class	Cure : virtual public AMateria
{
	public:
		Cure();
		Cure(const Cure &src);
		Cure& operator=(const Cure &src);
		~Cure();

		Cure* clone() const;
		void use(ICharacter &target);
};
