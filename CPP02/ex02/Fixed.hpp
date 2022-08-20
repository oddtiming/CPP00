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
	Fixed( int const n );
	Fixed( float const f );
	Fixed( Fixed const & src );
	Fixed &	operator=( Fixed const & rhs );
	Fixed	operator+( Fixed const & rhs ) const;
	Fixed	operator-( Fixed const & rhs ) const;
	Fixed	operator*( Fixed const & rhs ) const;
	Fixed	operator/( Fixed const & rhs ) const;
	Fixed	operator>( Fixed const & rhs ) const;
	Fixed	operator<( Fixed const & rhs ) const;
	Fixed	operator==( Fixed const & rhs ) const;
	Fixed	operator!=( Fixed const & rhs ) const;
	Fixed	operator>=( Fixed const & rhs ) const;
	Fixed	operator<=( Fixed const & rhs ) const;

	Fixed	operator++( void );						// Prefix
	Fixed 	operator++( int );				// Postfix
	Fixed	operator--( void );						// Note that prefix returns reference
	Fixed 	operator--( int );				// while postfix returns value.
	
	// a-- ==> a is decremented by 1, but previous value is returned. Hence the new instance.
	~Fixed( void );
	
	int		getRawBits( void ) const;
	int		getNbFract( void ) const;
	void	setRawBits( int const n );

	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream & operator<<( std::ostream & o, Fixed const & s );
#endif // FIXED_HPP_
