#ifndef PRESIDENTIAL_PARDON_FORM_HPP_
# define PRESIDENTIAL_PARDON_FORM_HPP_

# include "AForm.hpp"
# include <iostream>
# include <iomanip>
# include <string>

# define PRESIDENTIAL_GRADE_SIGN 25
# define PRESIDENTIAL_GRADE_EXEC 5

class PresidentialPardonForm : public AForm {

private:
/* Attributes */
	const std::string		_target;
/* Implementation of AForm's virtual abstract declaration */
	virtual void _executeFormAction( ) const;

public:

	/* Constructors */
	PresidentialPardonForm( );
	PresidentialPardonForm( std::string const & target );
	PresidentialPardonForm( PresidentialPardonForm const & src );

	/* Destructor */
	~PresidentialPardonForm( );

	/* Assignment operator */
	PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

	/* Getters / Setters */
	std::string const & getTarget( ) const;

};

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & s );

#endif // PRESIDENTIAL_PARDON_FORM_HPP_
