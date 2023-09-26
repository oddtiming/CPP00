
// 1 2 + : prefix notation aka functional notation : +( 1, 2 )
// 	Notation that could resemble a member function:
//	1.+( 2 ) instance `1' on which we call member function `+' with parameter `2'
// 1 + 2 : infix notation
// 1 2 + : postfix notation aka stack notation (val, val, push)

//	These are technically operator overloads.
#ifndef INTEGER_HPP_
# define INTEGER_HPP_

# include <iostream>

class Integer {

private:
/* Attributes */
	int _n;

public:
/* Functions */
	Integer( int const n );
	~Integer( void );

	int	getValue( void ) const;

	//	rhs = right-hand side
	Integer &	operator=( Integer const & rhs );
	Integer		operator+( Integer const & rhs ) const;

};

//	Non-member function operator overload
std::ostream &	operator<<( std::ostream & o, Integer const & rhs );

#endif // INTEGER_HPP_
