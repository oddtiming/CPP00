#ifndef BURAUCRAT_HPP_
# define BURAUCRAT_HPP_

# include <iostream>
# include <string>
# include <stdexcept>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Form;

class Bureaucrat
{

	public:
		// Exceptions
		class GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw() {
					return ("Bureaucrat requires a higher grade.");
				}
		};

		class GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw() {
					return ("Bureaucrat requires a lower grade.");
				}
		};
	
		// Constructors
		Bureaucrat( );
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat( std::string const & name, uint const & grade );

		// Assignment operator
		Bureaucrat &	operator=( Bureaucrat const & rhs );

		// Destructor
		~Bureaucrat( );

		// Getters/Setters
		std::string const & getName( ) const;
		uint const & 		getGrade( ) const;
		
		// Member functions
		void promote( );
		void demote( );

	/**
	*  
	*  	New Function
	*  
	*/
		void signForm( Form & toSign );
		void executeForm( Form & toSign );

	
	private:
		std::string		_name;
		uint			_grade;
	
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & s );

#endif // BURAUCRAT_HPP_
