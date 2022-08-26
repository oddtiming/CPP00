#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Bureaucrat::Bureaucrat( ) :
		_name( "unluckyGuy" ),
		_grade( 150 )
{
	std::cout << "Bureaucrat constructor called by " << _name 
	<< ". Grade given is : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( std::string const & name, uint const & grade ) :
		_name( name ),
		_grade( grade )
{
	if ( grade < MAX_GRADE ) {
		throw GradeTooHighException();
	}
	else if ( grade > MIN_GRADE ) {
		throw GradeTooLowException();
	}

	std::cout << "Bureaucrat parametric constructor called by " << _name 
	<< " with grade : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	std::cout << "Bureaucrat copy constructor called by " << _name << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat( )
{
	std::cout << "~Bureaucrat destructor called by " << _name << std::endl;
}

/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs ) {

	std::cout << "Bureaucrat assignment operator called by " << _name << std::endl;

	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();

	return *this;
}


/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string const &	 Bureaucrat::getName( ) const {
	return this->_name;
}

uint const &	 Bureaucrat::getGrade( ) const {
	return this->_grade;
}

/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void Bureaucrat::promote( ) {

	std::cout << *this << " asks for a promotion"
		<< "\n..." << std::endl;

	if (this->_grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	
	std::cout << this->_name << " got the promotion! \tGrade: [ "
	 << this->_grade << " ] ==> [ " << this->_grade - 1
	 << " ]\n" <<  std::endl;

	// Grade goes highest to lowest
	this->_grade--;
}

void Bureaucrat::demote( ) {

	std::cout << *this << " asks for a demotion..?"
		<< "\n..." << std::endl;

	if (this->_grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	
	std::cout << this->_name << " got demoted! Yay :D \tGrade: [ "
	 << this->_grade << " ] ==> [ " << this->_grade + 1
	 << " ]\n" <<  std::endl;

	// Grade goes highest to lowest
	this->_grade++;
}

void Bureaucrat::signForm( AForm & toSign ) {

	std::cout << *this << " asks to sign the form " << toSign.getName()
		<< "\n\t..." << std::endl;

	// Try/catch block to check if the bureaucrat is allowed to do that
	try {
		toSign.beSigned(*this);
		
 	} catch (std::exception & e) {
		std::cerr << *this << " could not sign the form because " << e.what() 
			<< "\n\n" << std::endl;
		return ;
 	}

	// In case of success 
	std::cout << *this << " has successfully signed the form: " << toSign.getName()
		<< "!\n" << std::endl;
}

void Bureaucrat::executeForm( AForm & toSign ) {

	std::cout << *this << " asks to execute the form " << toSign.getName()
		<< "\n\t..." << std::endl;

	// Try/catch block to check if the bureaucrat is allowed to do that
	try {
		toSign.execute( *this );

 	} catch (std::exception & e) {
		std::cerr << *this << " could not execute the form because " << e.what() 
			<< "\n\n" << std::endl;
		return ;
 	}

	// In case of success 
	std::cout << *this << " has successfully executed the form " << toSign.getName() 
		<< "!\n" << std::endl;

}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
