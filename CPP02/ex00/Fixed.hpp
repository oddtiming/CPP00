#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <string>
# include <iostream>

class Fixed {

private:
/* Attributes */
	int					_integer;
	static const int	_nbFractionalPoints = 8;

public:
/* Functions */
	Fixed( void );
	Fixed( Fixed const & src );
	Fixed &	operator=( Fixed const & rhs );
	~Fixed( void );
	
	int		getRawBits( void ) const;
	void	setRawBits( int const n );

};

std::ostream & operator<<( std::ostream & o, Fixed const & s );
#endif // FIXED_HPP_
