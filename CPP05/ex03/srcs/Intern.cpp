#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// Sorry, I just wanted to test variadic macros, 
// since we weren't allowed in C, hehe
#define OUT(s) { std::cout << (s) << "\n" << std::endl; }

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
std::string	Intern::_askBoss( uint const & i ) const 
{
	return ( "Boss, you asked for, but did you mean the form " 
		+ _formReqs[i][0] + " " + _formReqs[i][1] + "?");
}


// Returns true if the request matches exactly, or if it is shortened
bool	Intern::_glaresAtWords(std::string const & reqWord, 
							   std::string const & formWord ) const
{
	return ( reqWord == formWord.substr( 0, reqWord.length() )
		  && reqWord.length() > 2 );
}


void	Intern::_findForm( std::string const & req, uint & reqIndex ) const
{

	// Request is treated case insensitive
	std::string	reqToLower = strToLower( req );

	// stringstream to split words
	std::stringstream	reqss( reqToLower );

	std::string words[2];

	// Split string into individual words, discard whitespaces
	reqss >> std::ws >> words[0];
	reqss >> std::ws >> words[1];


	for ( uint i = 0; i < 3; i++ ) { // 3 == nb known forms

		// If first word doesn't match, check next form
		if ( _glaresAtWords( words[0], _formReqs[i][0] ) == false )
			continue ;

		// If req is half a match, prompt the user to know
		// if the current form was the intended match.
		// Otherwise, throw an Exception
		if ( _glaresAtWords( words[1], _formReqs[i][1] ) == false 
				&& ask_yn( _askBoss(i) ) == false )
			throw FormDoesNotExistException();
		
		// If two words match, assign form index to reqIndex
		reqIndex = i;
		return ;
	}
	// If no match is found
	throw FormDoesNotExistException();
}

/*****************************************************************************/
/*                          Public Member functions                          */
/*****************************************************************************/


AForm * Intern::makeForm( std::string const & request, std::string const & target ) const
{

	OUT("\nIntern is processing request: \"" + request + "\"" );

	uint	reqIndex = 0;
	
	// This seems useless, but this IS a module about exceptions
	try { 
		_findForm( request, reqIndex );
	}
	catch (FormDoesNotExistException e) {

		std::cout << e.what() << ": \"" << request << "\"\n" << std::endl;
		return NULL;
	}
	catch (std::exception e) { _displErr(e); }

	OUT("\n\t* Intern found "
			+ _formReqs[reqIndex][0] + " " 
			+ _formReqs[reqIndex][1] + " form! *");

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
	{ "shrubbery", "creation" },	// id = 0
	{ "robotomy", "request" },		// id = 1
	{ "presidential", "pardon" }	// id = 2
};
