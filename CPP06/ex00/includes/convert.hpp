#include <stdexcept>

using std::string;

enum e_types {
	T_NB,
	T_INF,
	T_NAN
};

class NotAnIntException : public std::exception {
	public :
		virtual const char * what() const throw() {
			return ("Error: input is not a valid number"); }
};

// utils.cpp
string	strToLower(string str);
int		getVarType( string const & str, size_t const & i, long double const & d ) ;
string	getWord(char * const str);

// print.cpp
void	convertNonNb( int const & varType );
void	convertNb( string &str, long double const & ldbl );
