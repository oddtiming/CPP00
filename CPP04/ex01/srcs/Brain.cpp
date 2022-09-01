#include "Brain.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

Brain::Brain( ) {
	std::cout << __FUNCTION__ << " called" << std::endl;
	return ;
}

Brain::Brain( Brain const & src ) :
	_ideas(src._ideas) 
{
	std::cout << __FUNCTION__ << " copy constructor called" << std::endl;

	*this = src;
}

Brain &	Brain::operator=( Brain const & rhs ) {
	std::cout << "Brain assignment operator called, but does nothing" << std::endl;
	this->_ideas = rhs._ideas;
	return *this;
}

Brain::~Brain( ) {
	std::cout << __FUNCTION__ << " called" << std::endl;
}

/*****************************************************************************/
/*                             Getters/Setters                               */
/*****************************************************************************/

std::string		Brain::getIdea( uint index ) const {
	
	return this->_ideas[index % 100];
}




std::string Brain::_ideas[100] = { "jolly_problem","encouraging_negotiation","common_opportunity", "brainy_child",
	"profuse_finding", "sleepy_writer","wholesale_tooth", "greasy_membership", "different_girl","whole_article","interesting_suggestion",
	"lewd_buyer","past_ear", "quizzical_drawer", "condemned_department", "lumpy_reading","unusual_procedure", "unhappy_nature", "special_penalty",
	"mundane_analysis", "sloppy_reality", "unwritten_director","sad_writing", "inquisitive_winner", "silky_resolution", "bored_engine",
	"clammy_physics", "piquant_replacement", "resolute_performance","opposite_leader", "boorish_army", "longing_disk", "whimsical_bird",
	"arrogant_player", "conscious_shopping", "clever_establishment", "voiceless_football", "four_refrigerator", "several_medicine",
	"two_teacher", "descriptive_salad", "oceanic_hall", "illustrious_childhood", "foamy_complaint", "tart_administration", "thirsty_marketing",
	"fluffy_device", "tested_perception", "fat_fishing", "learned_agreement",
	// Halfway mark
	"filthy_collection", "abandoned_impression", "torpid_historian",
	"penitent_university", "thoughtful_establishment", "comfortable_revolution", "oafish_baseball", "ruddy_software", "detailed_manager",
	"zesty_meal", "deranged_highway", "grumpy_song", "unable_nature", "severe_story", "wistful_development", "voracious_property",
	"jumbled_painting", "slimy_gene", "six_apartment", "violet_delivery", "flawless_information", "unlikely_health","foolish_insurance",
	"shrill_internet", "obnoxious_mom", "dangerous_complaint", "true_editor", "billowy_republic", "economic_exam", "chief_charity", 
	"miscreant_orange", "crazy_inspector", "future_department", "ill-informed_responsibility", "brawny_application", "puzzling_celebration", 
	"quarrelsome_audience", "tricky_penalty", "wide_analyst", "keen_child", "aloof_psychology", "marvelous_reading", "wacky_office",
	"aboriginal_disease", "uninterested_unit", "exclusive_courage", "permissible_thought", "rightful_mixture", "melodic_potato", "lying_finding" };
