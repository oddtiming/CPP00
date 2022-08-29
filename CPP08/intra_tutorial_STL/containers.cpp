#include "ClapTrap.hpp"
#include <iostream>
#include <list>
#include <map>
#include <vector>

class Clap;

using std::list;
using std::map;
using std::string;
using std::vector;
using std::cout;
using std::endl;

int	main( ) {
	list<int>					lst1;
	map<string, ClapTrap *>		map1;
	vector<int>					v1;
	vector<int>					v2(42, 100);

	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);

	ClapTrap					clapTrap1( "Clappy" );
	ClapTrap					clapTrap2( "Clapper" );
	ClapTrap					clapTrap3( "Clappier" );
	ClapTrap					clapTrap4( "Clappiest" );

	map1["clap1"] = &clapTrap1;
	map1["clap2"] = &clapTrap2;
	map1["clap3"] = &clapTrap3;
	map1["clap4"] = &clapTrap4;

	list<int>::const_iterator	it;
	list<int>::const_iterator	ite = lst1.end();

	for (it = lst1.begin(); it != ite; ++it) {
		cout << *it << endl;
	}

	map<string, ClapTrap *>::const_iterator itm;
	map<string, ClapTrap *>::const_iterator itme = map1.end();

	for (itm = map1.begin(); itm != itme; itm++) {
		cout << itm->first
			 << ":" 
			 << *itm->second
			 << endl;
	}

	map1.find("clap3")->second->beRepaired(100);

	return 0;
}
