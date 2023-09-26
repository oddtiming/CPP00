#include <stdio.h>

void	dump_32_bits_integer( int const n ) {

	printf("[%10d]: %u ", n, n >> 31);

	for (int i = 30; i >= 0 ; i-- ) {
		printf("%u", (n >> i) & 0b1 );
		if ( (i % 8) == 0 )
			printf(" ");
	}
	printf("\n");
}

void	dump_64_bits_double( double const n ) {

    unsigned char * desmond = (unsigned char *) &n;
    int i;
    int j;

	printf("[%10f]: %lu ", n, (long)n >> 63);
	i = sizeof(double);
    while (i--) {
		j = 8;
    	while (j--) {
        	printf ("%d", (desmond[i] >> j) & 0x1);
			if (i * 8 + j == 52)
				printf(" ");
		}
    }

	for (int i = 62; i >= 0 ; i-- ) {
		// printf("%lu", (n >> i) & (1 << i) );
	}
	printf("\n");
}
