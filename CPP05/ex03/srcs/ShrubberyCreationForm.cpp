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
	
	std::string		filename;

	filename = _target + "_shrubbery";

	std::ofstream	ofs( filename );

	if ( !ofs.is_open() ) {
		throw FileErrorException( filename );
	}

	ofs << _trees[0] << "\n\n" 
		<< _trees[1] << "\n\n" 
		<< _trees[2] << std::endl;

	ofs.close();

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
https://asciiart.website/index.php?art=plants/trees",

"\n\n\"ASCII trees\"\n\n",

"my-app/ \n\
├─ node_modules/ \n\
├─ public/ \n\
│  ├─ favicon.ico \n\
│  ├─ index.html \n\
│  ├─ robots.txt \n\
├─ src/ \n\
│  ├─ index.css \n\
│  ├─ index.js \n\
├─ .gitignore \n\
├─ package.json \n\
├─ README.md \n\
	"
};