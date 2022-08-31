#ifndef HARL_HPP_
# define HARL_HPP_

# include <string>
# include <iostream>

# define NB_MSGS 4
# define NB_LEVELS 4

class Harl {

typedef  void (Harl::*HarlMemFn)( void );

public:
	/* Functions */
	Harl( void );
	~Harl( void );
	void	complain( std::string level );
	
	/* Public attribute to allow main() to generate random tests */
	static std::string const	levels[NB_LEVELS];

private:
/* Functions */
	void		_debug( void );
	void		_info( void );
	void		_warning( void );
	void		_error( void );
	void		_dispatchMsg( int i );


/* Attributes */
	static std::string const	_debugMsgs[NB_MSGS];
	static std::string const	_infoMsgs[NB_MSGS];
	static std::string const	_warningMsgs[NB_MSGS];
	static std::string const	_errorMsgs[NB_MSGS];
};

#endif // HARL_HPP_
