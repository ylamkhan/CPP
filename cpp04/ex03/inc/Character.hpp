

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_MATERIA 4

class	Character : virtual public ICharacter
{
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &src);
		Character& operator=(const Character &src);
		~Character();
	
		const std::string &getName() const;
		AMateria*	getMateria(int idx) const;

		void equip(AMateria *materia);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria*	_inventory[MAX_MATERIA];
};
