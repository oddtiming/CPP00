#include "AForm.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

AForm::AForm( ) :
		_name( "default_secure" ),
		_isSigned( false ),
		_signGrade( 1 ),
		_executeGrade( 1 )
{
	std::cout << "AForm default constructor called by " << _name 
	<< ".\n\t-w- Sign Grade is : " << _signGrade << " -w-"
	<< ".\n\t--x Execute Grade is : " << _executeGrade << " --x" << std::endl;
}

AForm::AForm( std::string const & name, uint const & signGrade, uint const & executeGrade ) :
		_name( name ),
		_isSigned( false ),
		_signGrade( signGrade),
		_executeGrade( executeGrade )
{
	if ( signGrade < MAX_GRADE || executeGrade < MAX_GRADE ) {
		throw GradeTooHighException( _name );
	}
	else if ( signGrade > MIN_GRADE || executeGrade > MIN_GRADE ) {
		throw GradeTooLowException( _name );
	}

	std::cout << "AForm parametric constructor called by " << _name 
	<< ".\n\t Sign Grade is : " << _signGrade 
	<< ".\n\t Execute Grade is : " << _executeGrade<< std::endl;
}

AForm::AForm( AForm const & src ) :
	_name( src._name ),
	_isSigned( src._isSigned ),
	_signGrade( src._signGrade ),
	_executeGrade( src._executeGrade )
{
	std::cout << "AForm copy constructor called by " << _name << std::endl;
	*this = src;
}

AForm::~AForm( )
{
	std::cout << "~AForm destructor called by " << _name << std::endl;
}

/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

AForm &	AForm::operator=( AForm const & rhs ) {

	std::cerr << "AForm assignment operator called by " << _name
		<< "on" << rhs._name << ". Const objects cannot be assigned " << std::endl;

	return *this;
}


/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string const &	 AForm::getName( ) const { return this->_name; }
uint const &	 AForm::getSignGrade( ) const { return this->_signGrade; }
uint const &	 AForm::getExecuteGrade( ) const { return this->_executeGrade; }
bool const &	 AForm::isSigned( ) const { return this->_isSigned; }

/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void AForm::beSigned( Bureaucrat & bureaucrat ) {

	uint	grade = bureaucrat.getGrade();


	// Throw exception if necessary 
	if ( grade < MAX_GRADE )
		throw AForm::GradeTooHighException( _name );
	else if ( grade > MIN_GRADE || grade > _signGrade )
		throw AForm::GradeTooLowException( _name );
	else if ( _isSigned )
		throw AForm::FormAlreadySignedException( _name );
	
	_isSigned = true;

	//In case of success, success message will be printed by bureaucrat

}

void AForm::execute( Bureaucrat & bureaucrat ) const {

	uint	grade = bureaucrat.getGrade();

	// Throw exception if necessary 
	if ( grade < MAX_GRADE )
		throw AForm::GradeTooHighException( _name );
	else if ( grade > MIN_GRADE || grade > _executeGrade )
		throw AForm::GradeTooLowException( _name );
	else if ( this->_isSigned == false )
		throw AForm::FormNotSignedException( _name );

	
	// In case of success 
	this->_executeFormAction();
}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, AForm const & rhs ) {

	o << rhs.getName() << " form : \n" 
		<< "\n\t-w- Sign Grade is \t: " << rhs.getSignGrade() << "\t -w-"
		<< "\n\t--x Execute Grade is \t: " << rhs.getExecuteGrade() << "\t --x"
		<< "\n\t--x is it signed? \t: " << (rhs.isSigned() ? "yes" : "no") << "\t --x" << std::endl;
	return o;
}
