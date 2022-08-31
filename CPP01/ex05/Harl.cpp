#include "Harl.hpp"
#include <cstdlib>

Harl::Harl( void ) { return ; }
Harl::~Harl( void ) { return ; }

void	Harl::_debug( void ) {
	std::cout << this->_debugMsgs[ rand() % NB_MSGS ] << "\n" << std::endl;
}

void	Harl::_info( void ) {
	std::cout << this->_infoMsgs[ rand() % NB_MSGS ] << "\n" << std::endl;
}

void	Harl::_warning( void ) {

	std::cout << this->_warningMsgs[ rand() % NB_MSGS ] << "\n" << std::endl;
	return ;
}

void	Harl::_error( void ) {
	std::cout << this->_errorMsgs[ rand() % NB_MSGS ] << "\n" << std::endl;
}

void	Harl::_dispatchMsg( int i ) {
	
	void	(Harl::*fctsArr[4])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error };

	std::cout << "\n\t[ " << levels[i] << " ]" << std::endl;
	(this->*(fctsArr[i]))();
}

void	Harl::complain( std::string level ) {
	int	i = 0;

	for ( i = 0; i < NB_LEVELS; i++ )
		if ( level == levels[i] )
			return _dispatchMsg( i );

	if ( level ==  "RANDOM" ) {

		i = rand() % NB_LEVELS;
		_dispatchMsg( i );
	}
	else
		std::cout << "\nOof! My dude Harl don't even KNOW how to complain at that level." << std::endl;
}




std::string const	Harl::levels[NB_LEVELS] = { 
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR" };

std::string const	Harl::_debugMsgs[NB_MSGS] = { "I'm on the verge of tears by the time we arrive at Espace since I'm positive we won't have a decent table. But we do, and relief washes over me in an awesome wave.",
	"I can't believe Bryce prefers Van Pattons card to mine",
	"Has anyone really been far even as decided to use even go want to do look more like?",
	"is meatball an fruit" };


std::string const	Harl::_infoMsgs[NB_MSGS] = {  "Hey! Can you keep it down?? Im trying to do drugs!",
	"Don't sweat the petty things, and don't pet the sweaty things.",
	"Build a man a fire and he'll be warm for a night... Set a man on fire and he'll be warm for the rest of his life.",
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" };


std::string const	Harl::_warningMsgs[NB_MSGS] = { "I think I deserve to have some extra bacon for free. \nI’ve been coming for years whereas you started working here since last month.",
	"They don't think it be like it is, but it do.",
	"Outside of a dog, a book is a man's best friend. \nInside of a dog, it's too dark to read.",
	"Look up \"idiot\" in the dictionary. You know what you'll find? \nA picture of me? \nNo! The definition of the word idiot, which you fucking are!" };


std::string const	Harl::_errorMsgs[NB_MSGS] = { "If I had a gun with two bullets and I was in a room with Hitler, Bin Laden, and Toby, I would shoot you twice.",
	"If you were in the wild, I would attack you, even if you weren't in my food chain. I would go out of my way to attack you. If I were a lion and you were a tuna, I would swim out in the middle of the ocean and freaking eat you. And then I'd bang your tuna girlfriend.",
	"This is unacceptable! I want to speak to the manager now.",
	"UNACCEPTAAAAABBLLLLEEE!!!" };
