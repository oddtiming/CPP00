#ifndef SHRUBBERY_CREATION_FORM_HPP_
# define SHRUBBERY_CREATION_FORM_HPP_

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string>

# define SHRUBBERY_GRADE_SIGN 145
# define SHRUBBERY_GRADE_EXEC 137

class ShrubberyCreationForm : public AForm {

private:
	/* Attributes */
	const std::string			_target;
	
	/* Implementation of AForm's purely virtual function */
	virtual void _executeFormAction( ) const;

	/* Non-member attribute to store the trees */
	static std::string			_trees[3];

public:

	/* Constructors */
	ShrubberyCreationForm( );
	ShrubberyCreationForm( std::string const & target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );

	/* Destructor */
	~ShrubberyCreationForm( );

	/* Assignment operator */
	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );

	/* Getters / Setters */
	std::string const & getTarget( ) const;


	/* Exceptions */

	class FileErrorException : public std::exception {
		std::string		_e_msg;
		
		public:
			virtual ~FileErrorException( ) throw() { }
			FileErrorException( std::string const & filename ) : _e_msg(filename + "could not be opened") { }
			virtual const char* what() const throw() { return ( _e_msg.c_str() ); }
	};

};

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & s );

#endif // SHRUBBERY_CREATION_FORM_HPP_
