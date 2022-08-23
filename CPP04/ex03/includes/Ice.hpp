#ifndef ICE_HPP_
# define ICE_HPP_

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Ice : public AMateria
{
	private:
		std::string	_name;
	
	public:

		Ice( ) { }
		Ice( Ice const & src );
		Ice &	operator=( Ice const & rhs );

		~Ice( ) { }

		void use(ICharacter & target);
};

#endif // ICE_HPP_