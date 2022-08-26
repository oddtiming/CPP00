#ifndef FORM_HPP_
# define FORM_HPP_

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <stdexcept>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat;

class AForm
{

private:
	std::string const	_name;
	bool				_isSigned;
	uint const			_signGrade;
	uint const			_executeGrade;

protected:
	/**
	 * 	IMPORTANT: The following virtual function makes the class abstract
	 * 
	 */
	virtual void _executeFormAction( ) const = 0;

public:
	// Constructors
	AForm( );
	AForm( AForm const & src );
	AForm( std::string const & name, 
			uint const & signGrade, 
			uint const & executeGrade );

	// Assignment operator
	AForm &	operator=( AForm const & rhs );

	// Destructor
	virtual ~AForm( );

	// Getters/Setters
	std::string const & getName( ) const;
	uint const & 		getSignGrade( ) const;
	uint const & 		getExecuteGrade( ) const;
	bool const & 		isSigned( ) const;
	
	// Member functions
	void beSigned( Bureaucrat & bureaucrat );
	void execute( Bureaucrat & executor ) const;



	// Exceptions

	/**
	 *  https://stackoverflow.com/questions/23742448/c-how-to-pass-parameters-to-custom-exceptions
	 * 	Resource for exception subClasses
	 * 
	 *  https://stackoverflow.com/questions/59919357/weird-error-on-exception-specification-of-overriding-function-is-more-lax-than
	 * 	Why virtual destructor is necessary
	 * 
	 * 
	 * 		To pass string in Exception, best way seems to pass it as construction
	 * 
	 */

		class FormException : public std::exception {
			protected:
				std::string	_e_msg;

			public:
        		virtual ~FormException() throw() { return ; }
				FormException( std::string const & e_msg ) : _e_msg( e_msg ) { }
				virtual const char* what() const throw() { return _e_msg.c_str(); }
		};
		
		class GradeTooLowException : public FormException {
			public:
				GradeTooLowException( std::string const & en ) 
					: FormException( en + " form has already been signed." ) { }
		};
		class GradeTooHighException : public FormException {
			public:
				GradeTooHighException( std::string const & en ) 
					: FormException( en + " form has already been signed." ) { }
		};

		class FormAlreadySignedException : public FormException {
			public:
				FormAlreadySignedException( std::string const & en ) 
					: FormException( en + " form has already been signed." ) { }
		};

		class FormNotSignedException : public FormException {
			public:
				FormNotSignedException( std::string const & en ) 
					: FormException( en + " form has already been signed." ) { }
		};

		class InvalidTargetException : public FormException {
			public:
				InvalidTargetException( std::string const & en ) 
					: FormException( en + " form has already been signed." ) { }
		};


};

std::ostream & operator<<( std::ostream & o, AForm const & s );

#endif // FORM_HPP_
