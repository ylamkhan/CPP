

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>
# include "colors.hpp"

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &w);
		WrongAnimal &operator=(const WrongAnimal &w);
		~WrongAnimal();

		void makeSound();
	protected:
		std::string type;
};

#endif
