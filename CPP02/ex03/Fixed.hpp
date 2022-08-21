#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <string>
# include <iostream>


class Fixed {

private:
/* Attributes */
	int					_n;
	static const int	_nbFract = 8;

public:
/* Functions */
	Fixed( );
	Fixed( int const n );
	Fixed( float const f );
	Fixed( Fixed const & src );
	~Fixed( );

	Fixed &	operator=( Fixed const & rhs );

	/* Arithmetic operators */
	Fixed	operator + ( Fixed const & rhs ) const;
	Fixed	operator - ( Fixed const & rhs ) const;
	Fixed	operator - ( );
	Fixed	operator * ( Fixed const & rhs ) const;
	Fixed	operator / ( Fixed const & rhs ) const;

	/* Relational operators */
	bool	operator >  ( Fixed const & rhs ) const;
	bool	operator <  ( Fixed const & rhs ) const;
	bool	operator == ( Fixed const & rhs ) const;
	bool	operator != ( Fixed const & rhs ) const;
	bool	operator >= ( Fixed const & rhs ) const;
	bool	operator <= ( Fixed const & rhs ) const;

	/* Incrementers/decrementers */
	Fixed &	operator ++ ( );				// Prefix
	Fixed 	operator ++ ( int );				// Postfix
	Fixed &	operator -- ( );				// Note that prefix returns reference
	Fixed 	operator -- ( int );				// while postfix returns value.
	// a-- ==> a is decremented by 1, but previous value is returned. 
	// Hence the new instance.
	
	
	/* Getters/setters */
	int		getRawBits( ) const;
	int		getNbFract( ) const;
	void	setRawBits( int const n );

	float	toFloat( ) const;
	int		toInt( ) const;

	/* Class functions */
	static Fixed &			min( Fixed & a, Fixed & b );
	static Fixed const &	min( Fixed const & a, Fixed const & b );
	static Fixed const &	max( Fixed const & a, Fixed const & b );
	static Fixed &			max( Fixed & a, Fixed & b );

};

std::ostream & operator<<( std::ostream & o, Fixed const & s );

#endif // FIXED_HPP_
