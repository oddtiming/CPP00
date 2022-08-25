#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


#include <sstream>

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Intern::Intern( )
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern( Intern const & src )
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern( )
{
	std::cout << "~Intern destructor called" << std::endl;
}

/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

Intern &	Intern::operator=( Intern const & rhs ) {
	(void) rhs;
	return *this;
}

/*****************************************************************************/
/*                          Private Member functions                         */
/*****************************************************************************/


// Returns true if the request matches exactly, or if it is a shorthand
std::string	Intern::_askBoss( uint const & i ) {
	return ( "Boss, did you mean the form " 
		+ _formReqs[i][0] + " " + _formReqs[i][1] + "?");
}

// Returns true if the request matches exactly, or if it is shortened
bool	Intern::_glaresAtWords( 
	std::string const & reqWord, std::string const & formWord ) {

	return ( reqWord == formWord.substr( 0, reqWord.length() )
		&& reqWord.length() > 2 );
}


void	Intern::_findForm( std::string const & req, uint & reqIndex ) {

	// Request is case insensitive
	std::string	reqToLower = cleanString( req );

	// stringstream to split
	std::stringstream	reqss( reqToLower );

	std::string words[2];

	// To compare individually
	std::getline(reqss, words[0], ' ');
	std::getline(reqss, words[1], ' ');

	for ( uint i = 0; i < 3; i++ ) { // There are 3 known forms

		// If first work doesn't match, check next form
		if ( _glaresAtWords( words[0], _formReqs[i][0] ) == false )
			continue ;

		// If it is half a match, prompt the user to know
		// if it was the intended match.
		// Otherwise, throw an Exception
		if ( _glaresAtWords( words[1], _formReqs[i][1] ) == false 
				&& ask_yn( _askBoss(i) ) )
			throw FormDoesNotExistException();
		
		// If two words match, assign reqIndex
		reqIndex = i;
		return ;
	}
}

/*****************************************************************************/
/*                          Public Member functions                          */
/*****************************************************************************/


AForm * Intern::makeForm( std::string const & request, std::string const & target ) {

	std::cout << "Intern is processing request :\""
		<< request << "\"" << std::endl;

	uint	reqIndex = 0;
	
	// This seems useless, but this IS a module about exceptions
	try { 
		_findForm( request, reqIndex );
	}
	catch (FormDoesNotExistException e) {

		std::cout << e.what() << ": \"" << request << "\"" << std::endl;
		return NULL;
	}
	catch (std::exception e) { displErr(e); }

	switch ( reqIndex ) {
		case 0:
			return new ShrubberyCreationForm( target );
		case 1:
			return new RobotomyRequestForm( target );
		case 2:
			return new PresidentialPardonForm( target );
	}

	// will never be reached
	return NULL;
}


const std::string Intern::_formReqs[3][2] = {
	{ "shrubbery", " creation" },	// id = 0
	{ "robotomy", " request" },		// id = 1
	{ "presidential", " pardon" }	// id = 2
};
