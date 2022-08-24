#include "Form.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Form::Form( ) :
		_name( "default_secure" ),
		_isSigned( false ),
		_signGrade( 1 ),
		_executeGrade( 1 )
{
	std::cout << "Form default constructor called by " << _name 
	<< ".\n\t-w- Sign Grade is : " << _signGrade << " -w-"
	<< ".\n\t--x Execute Grade is : " << _executeGrade << " --x" << std::endl;
}

Form::Form( std::string const & name, uint const & signGrade, uint const & executeGrade ) :
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

	std::cout << "Form parametric constructor called by " << _name 
	<< ".\n\t Sign Grade is : " << _signGrade 
	<< ".\n\t Execute Grade is : " << _executeGrade<< std::endl;
}

Form::Form( Form const & src ) :
	_name( src._name ),
	_isSigned( src._isSigned ),
	_signGrade( src._signGrade ),
	_executeGrade( src._executeGrade )
{
	std::cout << "Form copy constructor called by " << _name << std::endl;
	*this = src;
}

Form::~Form( )
{
	std::cout << "~Form destructor called by " << _name << std::endl;
}

/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

Form &	Form::operator=( Form const & rhs ) {

	std::cerr << "Form assignment operator called by " << _name
		<< "on" << rhs._name << ". Const objects cannot be assigned " << std::endl;

	return *this;
}


/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string const &	 Form::getName( ) const { return this->_name; }
uint const &	 Form::getSignGrade( ) const { return this->_signGrade; }
uint const &	 Form::getExecuteGrade( ) const { return this->_executeGrade; }
bool const &	 Form::isSigned( ) const { return this->_isSigned; }

/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void Form::beSigned( Bureaucrat & bureaucrat ) {

	uint	grade = bureaucrat.getGrade();


	// Throw exception if necessary 
	if ( grade < MAX_GRADE )
		throw Form::GradeTooHighException( _name );
	else if ( grade > MIN_GRADE || grade > _signGrade )
		throw Form::GradeTooLowException( _name );
	else if ( _isSigned )
		throw Form::FormAlreadySignedException( _name );
	
	_isSigned = true;

	// In case of success 
	std::cout << bureaucrat.getName() 
		<< " has successfully signed the form: " << _name 
		<< "!" << "\n\n" << std::endl;

}

void Form::beExecuted( Bureaucrat & bureaucrat ) {

	uint	grade = bureaucrat.getGrade();

	// Throw exception if necessary 
	if ( grade < MAX_GRADE )
		throw Form::GradeTooHighException( _name );
	else if ( grade > MIN_GRADE || grade > _executeGrade )
		throw Form::GradeTooLowException( _name );
	else if ( this->_isSigned == false )
		throw Form::FormNotSignedException( _name );

	
	// In case of success 
	std::cout << bureaucrat.getName() 
		<< " has successfully executed the form: " << _name 
		<< "!" << "\n\n" << std::endl;

}


/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, Form const & rhs ) {

	o << rhs.getName() << " form : \n" 
		<< "\n\t-w- Sign Grade is \t: " << rhs.getSignGrade() << "\t -w-"
		<< "\n\t--x Execute Grade is \t: " << rhs.getExecuteGrade() << "\t --x"
		<< "\n\t--x is it signed? \t: " << (rhs.isSigned() ? "yes" : "no") << "\t --x" << std::endl;
	return o;
}
