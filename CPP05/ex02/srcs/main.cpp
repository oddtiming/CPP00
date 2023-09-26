#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>

void	_displErr( std::exception & e ) {

	std::cerr << "\n" << e.what() << std::endl;
}

int main( ) {

	Bureaucrat topBob( "topBob", 1 );
	Bureaucrat middleBob( "middleBob", 45 );
	Bureaucrat lowerBob( "lowerBob", 140 );

	// Specifies the target
	PresidentialPardonForm	presF( "Obama" );
	ShrubberyCreationForm	shrubF( "home" );
	RobotomyRequestForm		robotF( "IBM Watson" );

	// To demonstrate specific << overload
	std::cout << presF << std::endl;
	std::cout << shrubF << std::endl;
	std::cout << robotF << std::endl;

	// Needs valid target to be created
	try { 
		PresidentialPardonForm wrongForm( "" ); }
			catch (std::exception & e) { _displErr(e); }

	// Grade too low to sign, error caught in bureaucrat
	try { 
		lowerBob.signForm( shrubF ); }
			catch (std::exception & e) { _displErr(e); }


	// Cannot execute unsigned form
	try { 
		topBob.executeForm( presF ); }
			catch (std::exception & e) { _displErr(e); }


	// Form already signed
	try { 
		topBob.signForm( presF ); }
			catch (std::exception & e) { _displErr(e); }

	topBob.signForm( robotF );
	
	middleBob.demote( );

	// Now has grade too low
	try { 
		middleBob.executeForm( robotF ); }
			catch (std::exception & e) { _displErr(e); }

	// Should succeed 50% of the time in robotomizing $target
	topBob.executeForm( robotF );
	topBob.executeForm( robotF );
	topBob.executeForm( robotF );
	topBob.executeForm( robotF );

	// Should write ASCII trees to ./$target`_shrubbery'
	middleBob.signForm( shrubF );
	middleBob.executeForm( shrubF );

	// Should pardon $target
	topBob.signForm( presF );
	topBob.executeForm( presF );

	
	return 0;
}
