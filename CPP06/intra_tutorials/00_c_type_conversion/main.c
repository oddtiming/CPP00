
void	dump_32_bits_integer( int const n );
void	dump_64_bits_double( double const n );

int	main( )
{

	int		a = 42;			// Reference value

	double	b = a;			// Implicit conversion cast
	double	c = (double) a;	// Explicit conversion cast

	double	d = a;			// Implicit promotion	--> OK

	// Note : -Wno-conversion can be used to trigger errors
	int		e = d;			// Implicit demotion	--> Hazardous, int is less precise
	int		f = (int) d;	// Explicit demotion	--> OK, b/c explicit


	dump_32_bits_integer(a);
	dump_64_bits_double(b);
	dump_64_bits_double(c);
	dump_64_bits_double(d);
	dump_32_bits_integer(e);
	dump_32_bits_integer(f);

	return 0;

}
