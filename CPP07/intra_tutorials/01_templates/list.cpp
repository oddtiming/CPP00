#include <iostream>

template< typename T, typename U >
class List {

public:
	List<T, U>( T const & content1, U const & content2 ) { }
	List<T, U>( List<T, U> const & list1, List<T, U> const & list2 ) { }
	List<T, U>(  ) { }
	~List<T, U>(  ) { std::cout << "~List called" << std::endl; }

private:
	T *			_content1;
	U *			_content2;
	List<T, U> *	_next;

};


int	main( ) {

	List< int, float >			a( 42, 4.2f );
	List< float, double >		b( -8.73f, 9e300 );
	List< List< int, float >, List<char, bool> >	c( a, List< char, bool >('c', true) );


	return 0;

}