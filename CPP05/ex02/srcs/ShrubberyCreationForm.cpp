#include "ShrubberyCreationForm.hpp"

/*****************************************************************************/
/*                        Constructors/Destructors                           */
/*****************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm( ) :
		AForm( "ShrubberyCreationForm",
				SHRUBBERY_GRADE_SIGN,
				SHRUBBERY_GRADE_EXEC ),
		_target( "default_target" )
{
	std::cout << "ShrubberyCreationForm default constructor called on "
		<< _target << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) :
		AForm( "ShrubberyCreationForm",
				SHRUBBERY_GRADE_SIGN,
				SHRUBBERY_GRADE_EXEC ),
		_target( target )
{

	if ( target.empty() )
		throw InvalidTargetException( "ShrubberyCreationForm" );

	std::cout << "ShrubberyCreationForm parametric constructor called on "
		<< _target << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) :
	AForm( "ShrubberyCreationForm",
			SHRUBBERY_GRADE_SIGN,
			SHRUBBERY_GRADE_EXEC ),
	_target( src._target )
{
	std::cout << "ShrubberyCreationForm copy constructor called on " << _target << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( )
{
	std::cout << "~ShrubberyCreationForm destructor called by " << _target << std::endl;
}

/*****************************************************************************/
/*                           Assignment operator                             */
/*****************************************************************************/

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {

	std::cerr << "ShrubberyCreationForm assignment operator called by "
		<< this->getName()	<< "on" << rhs.getName()
		<< ". Const attributes cannot be assigned " << std::endl;

	return *this;
}

/*****************************************************************************/
/*                              Getters/Setters                              */
/*****************************************************************************/

std::string const &	 ShrubberyCreationForm::getTarget( ) const { return this->_target; }


/*****************************************************************************/
/*                              Member functions                             */
/*****************************************************************************/

void ShrubberyCreationForm::_executeFormAction(  ) const {
	
	static int treeIndex = 0;

	std::cout 
		<< "bbbZzZZzZZZZzzvv"
		<< "brbrbrbrbrrrrrbrrbrrrRRRRRRrrRRRRvvvvvvRrR"
		<< "* clink *" << "\n" << std::endl;


	std::string		filename;
	std::ofstream	ofs;


	// std::ios_base::app is append open_mode
	ofs.open( filename, std::ios_base::app );

	if ( !ofs.is_open() ) {
		throw FileErrorException( filename );
	}

	ofs << _trees[treeIndex];

	++treeIndex %= 3;	// There are only 3 types of trees, sorry for the magic number

}

/*****************************************************************************/
/*                            Non-member functions                           */
/*****************************************************************************/

std::ostream &	operator<<( std::ostream & o, ShrubberyCreationForm const & rhs ) {

	o << rhs.getName() << " form :" 
		<< "\n\t-w- Sign Grade is \t: " << rhs.getSignGrade() << "\t -w-"
		<< "\n\t--x Execute Grade is \t: " << rhs.getExecuteGrade() << "\t --x"
		<< "\n\t--x is it signed? \t: " << (rhs.isSigned() ? "yes" : "no") << "\t --x"
		<< "\n\t--x Target \t\t: " << rhs.getTarget() << std::endl;
	return o;
}


std::string	ShrubberyCreationForm::_trees[3] = {
		"The Worm's Turn						\n\
													\n\
		             _{\\ _{\\{\\/}/}/}__ \n\
		            {/{/\\}{/{/\\}(\\}{/\\} _ \n\
		           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _ \n\
		        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\} \n\
		       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/} \n\
		      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/} \n\
		     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\} \n\
		     _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\} \n\
		    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\} \n\
		     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/} \n\
		      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_) \n\
		     {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/} \n\
		      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\} \n\
		        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\} \n\
		         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_) \n\
		           {/{/{\\{\\/}{/{\\{\\{\\(_)/} \n\
		            {/{\\{\\{\\/}/}{\\{\\\\}/} \n\
		             {){/ {\\/}{\\/} \\}\\} \n\
		             (_)  \\.-'.-/ \n\
		         __...--- |'-.-'| --...__ \n\
		  _...--'   .-'   |'-.-'|  ' -.  ''--..__ \n\
		-'    ' .  . '    |.'-._| '  . .  '   jro \n\
		.  '-  '    .--'  | '-.'|    .  '  . ' \n\
		         ' ..     |'-_.-| \n\
		 .  '  .       _.-|-._ -|-._  .  '  . \n\
		             .'   |'- .-|   '. \n\
		 ..-'   ' .  '.   `-._.-`   .'  '  - . \n\
		  .-' '        '-._______.-'     '  . \n\
		       .      ~, \\n\
		   .       .   |\\   .    ' '-. \n\
		   ___________/  \\____________ \n\
		  /  Why is it, when you want \\ \n\
		 |  something, it is so damn   | \n\
		 |    much work to get it?     | \n\
		  \\___________________________/ \n\
		 \n\
		------------------------------------------------ \n\
		Thank you for visiting https://asciiart.website/ \n\
		This ASCII pic can be found at \n\
		https://asciiart.website/index.php?art=plants/trees",

		"ASCII trees",

		"my-app/ \
		├─ node_modules/ \
		├─ public/ \
		│  ├─ favicon.ico \
		│  ├─ index.html \
		│  ├─ robots.txt \
		├─ src/ \
		│  ├─ index.css \
		│  ├─ index.js \
		├─ .gitignore \
		├─ package.json \
		├─ README.md \
		"
	};