
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int			_value;
		static int	_fract;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed(int const n);
		Fixed(float const n);
		Fixed&	operator=(Fixed const &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif
