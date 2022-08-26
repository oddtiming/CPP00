#ifndef INTERN_HPP_
# define INTERN_HPP_

# include <iostream>
# include <string>

// Util functions
std::string	strToLower(std::string str);
bool		ask_yn( std::string prompt );
void		_displErr( std::exception & e );

class AForm;

class Intern
{
private:
	// Assignment operator is private b/c useless
	Intern &	operator=( Intern const & rhs );

	// Helper functions
	void		_findForm( std::string const & request, uint & reqIndex );
	bool		_glaresAtWords( std::string const & reqWord, std::string const & formWord );
	
	/* Prompts user for a yes/no confirmation on close match */
	std::string	_askBoss( uint const & i );

	static std::string const _formReqs[3][2];
	// shrubbery		: id = 0
	// robotomy			: id = 1
	// presidential		: id = 2

public:
	// Constructors
	Intern( );
	Intern( Intern const & src );
	
	// Destructor
	~Intern( );

	/* Returns a pointer to a new AForm object. Needs to be freed */
	AForm * makeForm(
		std::string const & request, std::string const & target);

	// Exceptions
	class FormDoesNotExistException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("InternException: Sorry boss, that form doesn't exist.");
			}
	};
	
};

#endif // INTERN_HPP_
