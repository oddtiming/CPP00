#include "Intern.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
void	displErr( std::exception & e );

int main( ) {

	Bureaucrat bigBoss( "bigBoss", 1 );

	AForm	*presPtr;
	AForm	*shrubPtr;
	AForm	*robotPtr;

	Intern intern;

	std::cout << std::setw(40) << std::setfill('*') << "\n";
	std::cout << "\t* Pattern matching test *" << "\n";
	std::cout << std::setw(40) << std::setfill('*') << std::endl
;
	shrubPtr = intern.makeForm( "shrubbery creation", "home" );
	delete shrubPtr;
	shrubPtr = intern.makeForm( "SHrubbERRY CreaTIoN", "home" );

	
	robotPtr = intern.makeForm( "robotomy request", "HAL 9000" );
	delete robotPtr;
	presPtr = intern.makeForm( "robot req", "HAL 9000" );

	presPtr = intern.makeForm( "pres pardon", "Obama" );
	delete presPtr;
	presPtr = intern.makeForm( "Pres Pard", "Obama" );

	std::cout << std::setw(40) << std::setfill('*') << "\n";
	std::cout << "\t* Form pointers test *" << "\n";
	std::cout << std::setw(40) << std::setfill('*') << std::endl;
	bigBoss.signForm( *shrubPtr );
	bigBoss.executeForm( *shrubPtr );
	bigBoss.signForm( *presPtr );
	bigBoss.executeForm( *presPtr );
	bigBoss.signForm( *robotPtr );
	bigBoss.executeForm( *robotPtr );

	delete shrubPtr;
	delete presPtr;
	delete robotPtr;

	return 0;
}
