#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_

# include <stdexcept>
# include <string>

class IntNotFoundException : public std::exception {
	std::string	const	_msg;

	public:
		virtual ~IntNotFoundException() throw() { return ; }
		IntNotFoundException( ) 
			: _msg( "IntNotFoundException" ) { }
		IntNotFoundException( int & i ) 
			: _msg( "IntNotFoundException: " + std::to_string(i) ) { }
		virtual const char* what() const throw() { return _msg.c_str(); }
};

class EmptyContainerException : public std::exception {
	public:
		virtual const char* what() const throw() { 
			return "EmptyContainerException"; }
};

#endif // EASYFIND_HPP_