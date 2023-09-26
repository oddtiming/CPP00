#ifndef BURAUCRAT_HPP_
# define BURAUCRAT_HPP_

# include <iostream>
# include <string>
# include <stdexcept>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{

	public:
		// Exceptions
		class GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw() {
					return ("GradeTooLowException: This Bureaucrat is already at the totem's bottom!");
				}
		};

		class GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw() {
					return ("GradeTooHighException: This Bureaucrat is already at the top of the totem!");
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

	// todo: NEEDS TO BE CONST
	private:
		std::string	const	_name;
		uint				_grade;
	
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & s );

#endif // BURAUCRAT_HPP_
