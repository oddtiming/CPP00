#include "PresidentialPardonForm.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

PresidentialPardonForm::PresidentialPardonForm( ) :
		AForm( "PresidentialPardonForm",
				PRESIDENTIAL_GRADE_SIGN,
				PRESIDENTIAL_GRADE_EXEC ),
		_target( "default_target" )
{
	std::cout << "PresidentialPardonForm default constructor called on "
		<< _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) :
		AForm( "PresidentialPardonForm",
				PRESIDENTIAL_GRADE_SIGN,
				PRESIDENTIAL_GRADE_EXEC ),
		_target( target )
{

	if ( target.empty() )
		throw InvalidTargetException( "PresidentialPardonForm" );

	std::cout << "PresidentialPardonForm parametric constructor called on "
		<< _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) :
	AForm( "PresidentialPardonForm",
			PRESIDENTIAL_GRADE_SIGN,
			PRESIDENTIAL_GRADE_EXEC ),
	_target( src._target )
{
	std::cout << "PresidentialPardonForm copy constructor called on " << _target << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( )
{
	std::cout << "~PresidentialPardonForm destructor called by " << _target << std::endl;
}

/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {

	std::cerr << "PresidentialPardonForm assignment operator called by " 
		<< this->getName()	<< "on" << rhs.getName() 
		<< ". Const attributes cannot be assigned " << std::endl;

	return *this;
}

/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string const &	 PresidentialPardonForm::getTarget( ) const { return this->_target; }


/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void PresidentialPardonForm::_executeFormAction(  ) const {
	
	// In case of success 
	std::cout << this->_target << " has been pardoned by Zaphod Beeblerox" << "\n"
		<< std::endl;

}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, PresidentialPardonForm const & rhs ) {

	o << rhs.getName() << " form :" 
		<< "\n\t-w- Sign Grade is \t: " << rhs.getSignGrade() << "\t -w-"
		<< "\n\t--x Execute Grade is \t: " << rhs.getExecuteGrade() << "\t --x"
		<< "\n\t--x is it signed? \t: " << (rhs.isSigned() ? "yes" : "no") << "\t --x"
		<< "\n\t--x Target \t\t: " << rhs.getTarget() << std::endl;
	return o;
}
