

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include "colors.hpp"
# include "Animal.hpp"

class	Brain
{
	public:
		Brain();
		Brain(const Brain &b);
		Brain &operator=(const Brain &b);
		~Brain();

		// Pour modularité
		const static int nbIdeas = 100;

		// Getters & Setters
		std::string	getIdea(int index);
		void		setIdea(int index, const std::string idea);
	private:
		std::string	ideas[nbIdeas];
};

#endif
