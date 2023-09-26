#include <fstream>
#include <iostream>

int	main( void ) {

	// ifstream = input filestream
	std::ifstream	ifs("numbers.txt");
	uint			dst1;
	uint			dst2;

	ifs >> dst1 >> dst2;
	std::cout << "dst1: " << dst1 << "\tdst2: " << dst2 << std::endl;
	ifs.close();

	std::ofstream	ofs("test.out");

	ofs << "I love this shit" << std::endl;
	ofs.close();

	return 0;
}
