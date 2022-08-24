#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// class ShrubberyCreationForm : public AForm {

// public:

// 	/* Constructors */
// 	ShrubberyCreationForm( );
// 	ShrubberyCreationForm( std::string const & target );
// 	ShrubberyCreationForm( ShrubberyCreationForm const & src );

// 	/* Destructor */
// 	~ShrubberyCreationForm( );

// 	/* Assignment operator */
// 	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );

// 	/* Getters / Setters */
// 	std::string const & getTarget( ) const;


// 	/* Exceptions */

// 	class FileErrorException : public std::exception {
// 		std::string		_e_msg;
		
// 		public:
// 			virtual ~FileErrorException( ) throw() { }
// 			FileErrorException( std::string const & filename ) : _e_msg(filename + "could not be opened") { }
// 			virtual const char* what() const throw() { return ( _e_msg.c_str() ); }
// 	};

// private:
// /* Attributes */
// 	const std::string			_target;
// /* Implementation of AForm's virtual abstract declaration */
// 	virtual void _executeFormAction( ) const;


// /* Non-member attribute to store the trees */
// 	static std::string			_trees[3];
// };

int main( ) {

	Bureaucrat topBob( "topBob", 1 );
	Bureaucrat middleBob( "middleBob", 52 );
	Bureaucrat lowerBob( "lowerBob", 140 );

	PresidentialPardonForm	PresidentialPardonForm( "Obama" );
	ShrubberyCreationForm	ShrubberyCreationForm( "home" );
	RobotomyRequestForm		RobotomyRequestForm( "IBM Watson" );


	// What is the best try/catch aesthetic? 
	// The compact
	// try {
	// 	// Grade too high
	// 	Bureaucrat wrongBob( "wrongBob", 0); } catch (std::exception & e) { std::cerr << "\n" << e.what() << std::endl;	}

	// // The new age
	// try {
	// 	// Grade too low
	// 	Form wrongForm( "wrongForm", 1, 152 );
 	// } catch (std::exception & e) {
	// 	std::cerr << "\n" << e.what() << std::endl;
 	// }


	// // The old school
	// try
	// {
	// 	// Signed twice
	// 	topBob.signForm( topForm );
	// 	topBob.signForm( topForm );
	// }
	// catch (std::exception & e)
	// {
	// 	std::cerr << "\n" << e.what() << std::endl;
 	// }
	

	// topBob.demote( );

	// // The misaligned
	// // Wrong permission to sign
	// try { lowerBob.signForm( topForm ); }
	// catch (std::exception & e) { std::cerr << "\n" << e.what() << std::endl; }

	// middleBob.executeForm( topForm );

	// // Unsigned form
	// try { topBob.executeForm( middleForm ); }
	// catch (std::exception & e) { std::cerr << "\n" << e.what() << std::endl; }

	
	// topBob.signForm( middleForm );
	// middleBob.executeForm( middleForm );
	
	// middleBob.demote( );

	// // Wrong permission to execute
	// try { middleBob.executeForm( middleForm ); }
	// catch (std::exception & e) { std::cerr << "\n" << e.what() << std::endl; }
	 

	return 0;
}
