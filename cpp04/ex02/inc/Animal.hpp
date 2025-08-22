
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "colors.hpp"

class	Animal
{
	public:
		Animal();
		Animal(const Animal &a);
		Animal &operator=(const Animal &a);
		virtual ~Animal();

		virtual void makeSound() const = 0;
	protected:
		std::string type;
};

#endif
