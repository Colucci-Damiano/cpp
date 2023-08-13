
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target )
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
		AForm::execute( executor );
		std::ofstream	ofs((this->_target + "_shrubbery").c_str());

		ofs << "                                              .    \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%;  %;   \n\
                    :         ;                   :;%;'     .,   \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  ;%;;%;        ,     %;    ;%;    ,%'\n\
              %;       %;;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        ;%; ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%;;%;;.%;'\n\
                 `:;%.    ;%;;%. %@;        %; ;@%;;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'   \n\
                        `@%.  `;@%.      ;@@%;         \n\
                          `@%;;%. `@%;;%    ;@@%;       \n\
                            ;@%. :@%;;%;  %@@%;       \n\
                              %@bd%; %; %bd%; %:;     \n\
                                #@%; %; %;: %; %:;;\n\
                                %@@%;;%;;%::;\n\
                                %@@@%(o);  . '         \n\
                                %@@@o%;:(.,'         \n\
                            `.. %@@@o%::;         \n\
                               `)@@@o%::;         \n\
                                %@@(o)::;        \n\
                               .%@@@@%::;         \n\
                               ;%@@@@%::;.          \n\
                              ;%@@@@%;;%:;;;. \n\
                          ...;%@@@@@%;;%:;;;;,..";
		ofs.close();
}

AForm*  ShrubberyCreationForm::generate( std::string const & target )
{
  return (new ShrubberyCreationForm(target));
}