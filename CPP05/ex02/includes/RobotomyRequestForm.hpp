#ifndef ROBOTOMY_REQUEST_FORM_HPP_
# define ROBOTOMY_REQUEST_FORM_HPP_

# include "AForm.hpp"
# include <iostream>
# include <iomanip>
# include <string>

# define ROBOTOMY_GRADE_SIGN 72
# define ROBOTOMY_GRADE_EXEC 45

class RobotomyRequestForm : public AForm {

private:
	/* Attributes */
	const std::string		_target;

	/* Implementation of AForm's purely virtual function */
	virtual void _executeFormAction( ) const;

public:

	/* Constructors */
	RobotomyRequestForm( );
	RobotomyRequestForm( std::string const & target );
	RobotomyRequestForm( RobotomyRequestForm const & src );

	/* Destructor */
	~RobotomyRequestForm( );

	/* Assignment operator */
	RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );

	/* Getters / Setters */
	std::string const & getTarget( ) const;

};

std::ostream & operator<<( std::ostream & o, RobotomyRequestForm const & s );

#endif // ROBOTOMY_REQUEST_FORM_HPP_
