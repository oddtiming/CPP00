#include "RobotomyRequestForm.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

RobotomyRequestForm::RobotomyRequestForm( ) :
		AForm( "RobotomyRequestForm",
				ROBOTOMY_GRADE_SIGN,
				ROBOTOMY_GRADE_EXEC ),
		_target( "default_target" )
{
	std::cout << "RobotomyRequestForm default constructor called on "
		<< _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) :
		AForm( "RobotomyRequestForm",
				ROBOTOMY_GRADE_SIGN,
				ROBOTOMY_GRADE_EXEC ),
		_target( target )
{

	if ( target.empty() )
		throw InvalidTargetException( "RobotomyRequestForm" );

	std::cout << "RobotomyRequestForm parametric constructor called on "
		<< _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) :
	AForm( "RobotomyRequestForm",
			ROBOTOMY_GRADE_SIGN,
			ROBOTOMY_GRADE_EXEC ),
	_target( src._target )
{
	std::cout << "RobotomyRequestForm copy constructor called on " << _target << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( )
{
	std::cout << "~RobotomyRequestForm destructor called by " << _target << std::endl;
}

/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {

	std::cerr << "RobotomyRequestForm assignment operator called by "
		<< this->getName()	<< "on" << rhs.getName() 
		<< ". Const attributes cannot be assigned " << std::endl;

	return *this;
}

/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string const &	 RobotomyRequestForm::getTarget( ) const { return this->_target; }


/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void RobotomyRequestForm::_executeFormAction(  ) const {
	
	static bool isLucky = true;

	
	std::cout 
		<< "bbbZzZZzZZZZzzvv"
		<< "brbrbrbrbrrrrrbrrbrrrRRRRRRrrRRRRvvvvvvRrR"
		<< "* clink *" << "\n" << std::endl;

	if ( isLucky ) {
		std::cout << this->_target << " was successfully robotomized!" << "\n"
			<< std::endl;

	}
	else  {
		std::cout << this->_target << "'s Robotomy was... not a success." << "\n"
			<< std::endl;
		std::cout << this->_target << "'s Robotomy was... not a success." << "\n"
			<< std::endl;
	}

	isLucky = !isLucky;

}

/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, RobotomyRequestForm const & rhs ) {

	o << rhs.getName() << " form :" 
		<< "\n\t-w- Sign Grade is \t: " << rhs.getSignGrade() << "\t -w-"
		<< "\n\t--x Execute Grade is \t: " << rhs.getExecuteGrade() << "\t --x"
		<< "\n\t--x is it signed? \t: " << (rhs.isSigned() ? "yes" : "no") << "\t --x"
		<< "\n\t--x Target \t\t: " << rhs.getTarget() << std::endl;
	return o;
}
