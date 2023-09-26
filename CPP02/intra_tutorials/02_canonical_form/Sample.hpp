#ifndef Sample_HPP_
# define Sample_HPP_

# include <iostream>

class Sample {

private:
/* Attributes */
	int	_n;

public:
/* Functions */
	Sample( void );								// CANONICAL FORM
	Sample( int const n );
	Sample( Sample const & src );				// CANONICAL FORM
	~Sample( void );							// CANONICAL FORM

	Sample &	operator=( Sample const & rhs );	// CANONICAL FORM

	int			getValue( void ) const;

};

std::ostream & operator<<( std::ostream & o, Sample const & s );

#endif // Sample_HPP_
