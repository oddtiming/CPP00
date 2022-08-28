
#pragma once

#include <cstddef>
#include <string>
#include <stdexcept>

class ArrayIndexOutOfBoundsException : public std::exception {
	std::string	_msg;

	public:
		virtual ~ArrayIndexOutOfBoundsException() throw() { return ; }
		ArrayIndexOutOfBoundsException( ) 
			: _msg( "ArrayIndexOutOfBoundsException" ) { }
		ArrayIndexOutOfBoundsException( size_t & i ) 
			: _msg( "ArrayIndexOutOfBoundsException at index: " + std::to_string(i) ) { }
		ArrayIndexOutOfBoundsException( size_t & i, size_t sz ) 
			: _msg( "ArrayIndexOutOfBoundsException at index: " 
			+ std::to_string(i) + ". size is " + std::to_string(sz) ) { }
		virtual const char* what() const throw() { return _msg.c_str(); }

};
