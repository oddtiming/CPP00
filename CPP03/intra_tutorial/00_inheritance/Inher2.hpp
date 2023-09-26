#include <string>

class Quadruped  { // Can access name, run(), and legs

private:
	std::string	name; // Only accessible from a Quadruped. Not from Dog

protected:
	int		legs[4]; // Only accessible from a Quadruped or a derived object

public:
	void	run(); // Accessible from wherever

};

// public, but could be 

class Doc : public Quadruped { // Can access run() and legs


};
