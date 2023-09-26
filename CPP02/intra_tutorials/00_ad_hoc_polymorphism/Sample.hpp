#ifndef SAMPLE_HPP_
# define SAMPLE_HPP_

# include <string>
# include <iostream>

class Sample {

public:

	Sample( void );
	~Sample( void );

	void	bar( char const c ) const;
	void	bar( int const c ) const;
	void	bar( float const c ) const;
	void	bar( Sample const c ) const;

};

#endif // SAMPLE_HPP_
