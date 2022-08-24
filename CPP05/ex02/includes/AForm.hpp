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
		~AForm( );

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
	 */

		
		class GradeTooLowException : public std::exception {
			std::string	_e_msg;

			public:
        		virtual ~GradeTooLowException() throw() { return ; }
				GradeTooLowException( std::string const & en ) : _e_msg( en + " form requires a higher grade." ) { }
				virtual const char* what() const throw() { return _e_msg.c_str(); }

		};

		class GradeTooHighException : public std::exception {
			std::string	_e_msg;

			public:
        		virtual ~GradeTooHighException() throw() { return ; }
				GradeTooHighException( std::string const & en ) : _e_msg( en + " form requires a lower grade." ) { }
				virtual const char* what() const throw() { return _e_msg.c_str(); }

		};

		class FormAlreadySignedException : public std::exception {
			std::string	_e_msg;

			public:
        		virtual ~FormAlreadySignedException() throw() { return ; }
				FormAlreadySignedException( std::string const & en ) : _e_msg( en + " form has already been signed." ) { }
				virtual const char* what() const throw() { return _e_msg.c_str(); }

		};

		class FormNotSignedException : public std::exception {
			std::string	_e_msg;

			public:
        		virtual ~FormNotSignedException() throw() { return ; }
				FormNotSignedException( std::string const & en ) : _e_msg( en + " form needs to be signed first." ) { }
				virtual const char* what() const throw() { return _e_msg.c_str(); }

		};

		class InvalidTargetException : public std::exception {
			std::string	_e_msg;

			public:
        		virtual ~InvalidTargetException() throw() { return ; }
				InvalidTargetException( std::string const & en ) : _e_msg( en + " needs a valid target." ) { }
				virtual const char* what() const throw() { return _e_msg.c_str(); }

		};



		// class GradeTooHighException : public std::exception {
		// 	std::string	_e_name;

		// 	public:
		// 		GradeTooHighException( std::string const & en ) : _e_name(en) { }
		// 		virtual const char* what() const throw() {

		// 			std::string msg = _e_name + " form requires a lower grade.";					
		// 			return msg->c_str();
		// 		}
		// };

		// class FormAlreadySignedException : public std::exception {
		// 	std::string	_e_name;

		// 	public:
		// 		FormAlreadySignedException( std::string const & en ) : _e_name(en) { }
		// 		virtual const char* what() const throw() {

		// 			std::string msg = _e_name + " form has already been signed.";					
		// 			return msg->c_str();
		// 		}
		// };

		// class FormNotSignedException : public std::exception {
		// 	std::string	_e_name;

		// 	public:
		// 		FormNotSignedException( std::string const & en ) : _e_name(en) { }
		// 		virtual const char* what() const throw() {

		// 			std::string msg = _e_name + " form needs to be signed first.";					
		// 			return msg->c_str();
		// 		}
		// };
	
};

std::ostream & operator<<( std::ostream & o, AForm const & s );

#endif // FORM_HPP_
