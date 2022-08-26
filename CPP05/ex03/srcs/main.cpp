#include "Intern.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <iomanip>

// Prototypes from utils.cpp
std::string	strToLower(std::string str);
bool		isQuitInput( std::string const & input );
void		_displErr( std::exception & e );
void		_printHeader( std::string const & text );


void	_askBossloop( Bureaucrat & bigBoss, Intern & intern )
{
	AForm	*formPtr;

	// Prompt first input - form name
	std::cout << "\n"
		<< "What form do you want, boss?" << "\n" 
		<< "\"Shrubbery Creation\", \"Robotomy Request\", or \"Presidential Pardon?\""
		<< "\n\t-> ";

	std::string	form;
	std::string	target;


	// Read first input - form name
	std::getline(std::cin >> std::ws, form);
	
	std::cout << form << std::endl;

	// Ctrl-D is treated as end of program
	if ( isQuitInput( form ) )
		exit( 0 );
	
	// Prompt second input - target name
	std::cout << "\n"
		<< "Who's our target?"
		<< "\n\t-> ";

	// Read second input - target name
	std::getline(std::cin >> std::ws, target);

	std::cout << target << std::endl;

	if ( isQuitInput( form ) )
		exit( 0 );

	formPtr = intern.makeForm( form, target );

	if ( formPtr ) {

		bigBoss.signForm( *formPtr );
		bigBoss.executeForm( *formPtr );
		delete formPtr;
	}

	_askBossloop( bigBoss, intern );
}


int main( ) {

	Bureaucrat bigBoss( "bigBoss", 1 );

	AForm	*presPtr;
	AForm	*shrubPtr;
	AForm	*robotPtr;
	AForm	*errPtr;

	Intern intern;


	// Invalid inputs
	_printHeader( "Invalid Inputs" );

	errPtr = intern.makeForm( "bli", "home" );
	errPtr = intern.makeForm( "", "home" );
	errPtr = intern.makeForm( "sh cr", "home" );

	// To showcase input recognition
	_printHeader( "Input Recognition" );

	robotPtr = intern.makeForm( "  rob req", "HAL 9000" );
	delete robotPtr;
	presPtr = intern.makeForm( " pres pardon", "Obama" );
	delete presPtr;
	errPtr = intern.makeForm( "SHrubB\t    CREATION !!!", "home" );
	delete errPtr;

	_printHeader( "Confirmation request on half-match" );
	// To showcase confirmation y/n prompt on half-matched requests
	errPtr = intern.makeForm( "shrubbery  ", "home" );
	delete errPtr;
	errPtr = intern.makeForm( "shrub execution", "home" );
	delete errPtr;

	// Forms to be tested
	shrubPtr = intern.makeForm( "\tshrubbery creation", "home" );
	presPtr = intern.makeForm( "\tPres Pard", "Obama" );
	robotPtr = intern.makeForm( "\trob req", "HAL 9000" );

	// Header
	// Test that the forms do work as intended
	_printHeader( "Test Forms" );

	bigBoss.signForm( *shrubPtr );
	bigBoss.executeForm( *shrubPtr );
	bigBoss.signForm( *presPtr );
	bigBoss.executeForm( *presPtr );
	bigBoss.signForm( *robotPtr );
	bigBoss.signForm( *robotPtr );
	bigBoss.executeForm( *robotPtr );

	delete shrubPtr;
	delete presPtr;
	delete robotPtr;


	// Prompt the user in a loop for forms and targets
	_askBossloop( bigBoss, intern );

	return 0;
}
