#include "Classes.hpp"

Base *	generate(void);
void	identify(Base * p);
void	identify(Base & p);

int	main( )
{
	Base *	ptr;

	for (int i = 0; i < 10; i++) {
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}

	return 0;
}
