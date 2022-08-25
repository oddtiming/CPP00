#ifndef INTERN_HPP_
# define INTERN_HPP_

# include <iostream>
# include <string>

// Util functions
std::string	cleanString(std::string str);
bool		ask_yn( std::string prompt );
void		displErr( std::exception & e );

class AForm;

class Intern
{
	private:
		// Assignment operator is useless so hidden
		Intern &	operator=( Intern const & rhs );

		void		_findForm( std::string const & request, uint & reqIndex );
		bool		_glaresAtWords( std::string const & reqWord, std::string const & formWord );
		std::string	_askBoss( uint const & i );

		// shrubbery = 0
		// robotomy = 1
		// presidential = 2
		static std::string const _formReqs[3][2];

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
