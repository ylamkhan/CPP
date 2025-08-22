
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int			_value;
		static int	_fract;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed&	operator=(Fixed const &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
