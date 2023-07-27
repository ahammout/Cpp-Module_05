/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:56:37 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 21:36:04 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ShrubberyCreationForm.hpp"

//---***------------------------------------- CONSTRUCTORS ---------------------------------***---//

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137)
{
    std::cout << "▷ " << this->getName() << " Default constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = "DefaultTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137)
{
    std::cout << "▷ " << this->getName() << " Parametred constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "◁ " << this->getName() << " Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &SRC) : AForm(SRC.getName(), SRC.getSignature(), SRC.getExGrade(), SRC.getSgrade())
{
    std::cout << "▷ " << this->getName() << " Copy constructor called" << std::endl;
    if (SRC.getSgrade() > 150 || SRC.getExGrade() > 150)
        throw GradeTooLowException();
    if (SRC.getSgrade() < 1 || SRC.getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = SRC.getTarget();
    *this = SRC;
    
}

//---***------------------------------------- OVERLOADING OPERATORS ---------------------------------***---//

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm &RightHand)
{
    ShrubberyCreationForm(RightHand._target);
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, ShrubberyCreationForm &REF)
{
    output << "▮▮▶ name ▶ " << REF.getName() << "\n    Signature ▶ " <<  REF.getSignature() << "\n    Sign grade ▶ " << REF.getSgrade() << "\n    Execute grade ▶ " << REF.getExGrade() << std::endl;
    return (output);
}

//---***------------------------------ EXCEPTION METHODS --------------------------***---//

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
    return (" Can't execute the form because his grade is low!");
}

//---***------------------------------ GETTERS --------------------------***---//

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

//---***------------------------------ SHRUBBERYCREATIONFORM METHODS --------------------------***---/
    
    
void    ShrubberyCreationForm::CreateShrubbery(std::string target) const
{
    std::fstream outfile;
    std::string filename;

    filename = target;
    filename.append("_shrubbery");
    outfile.open(filename, std::ios_base::out);
    if (!outfile.is_open())
    {
        std::cout << "╳: Error: can't open the file" << std::endl;
        exit(0);
    }
    outfile << "###########################'`################################" << std::endl;
    outfile << "###########################  V##'############################" << std::endl;
    outfile << "#########################V'  `V  ############################" << std::endl;
    outfile << "########################V'      ,############################" << std::endl;
    outfile << "#########`#############V      ,A###########################V" << std::endl;
    outfile << "########' `###########V      ,###########################V',#" << std::endl;
    outfile << "######V'   ###########l      ,####################V~~~~'',###" << std::endl;
    outfile << "#####V'    ###########l      ##P' ###########V~~'   ,A#######" << std::endl;
    outfile << "#####l      d#########l      V'  ,#######V~'       A#########" << std::endl;
    outfile << "#####l      ##########l         ,####V''         ,###########" << std::endl;
    outfile << "#####l        `V######l        ,###V'   .....;A##############" << std::endl;
    outfile << "#####A,         `######A,     ,##V' ,A#######################" << std::endl;
    outfile << "#######A,        `######A,    #V'  A########'''''##########''" << std::endl;
    outfile << "##########,,,       `####A,           `#''           '''  ,,," << std::endl;
    outfile << "#############A,                               ,,,     ,######" << std::endl;
    outfile << "######################oooo,                 ;####, ,#########" << std::endl;
    outfile << "##################P'                   A,   ;#####V##########" << std::endl;
    outfile << "#####P'    ''''       ,###             `#,     `V############" << std::endl;
    outfile << "##P'                ,d###;              ##,       `V#########" << std::endl;
    outfile << "##########A,,   #########A              )##,    ##A,..,ooA###" << std::endl;
    outfile << "#############A, Y#########A,            )####, ,#############" << std::endl;
    outfile << "###############A ############A,        ,###### ##############" << std::endl;
    outfile << "###############################       ,#######V##############" << std::endl;
    outfile << "###############################      ,#######################" << std::endl;
    outfile << "##############################P    ,d########################" << std::endl;
    outfile << "##############################'    d#########################" << std::endl;
    outfile << "##############################     ##########################" << std::endl;
    outfile << "##############################     ##########################" << std::endl;
    outfile << "#############################P     ##########################" << std::endl;
    outfile << "#############################'     ##########################" << std::endl;
    outfile << "############################P      ##########################" << std::endl;
    outfile << "###########################P'     ;##########################" << std::endl;
    outfile << "###########################'     ,###########################" << std::endl;
    outfile << "##########################       ############################" << std::endl;
    outfile << "#########################       ,############################" << std::endl;
    outfile << "########################        d###########P'    `Y#########" << std::endl;
    outfile << "#######################        ,############        #########" << std::endl;
    outfile << "######################        ,#############        #########" << std::endl;
    outfile << "#####################        ,##############b.    ,d#########" << std::endl;
    outfile << "####################        ,################################" << std::endl;
    outfile << "###################         #################################" << std::endl;
    outfile << "##################          #######################P'  `V##P'" << std::endl;
    outfile << "#######P'     `V#           ###################P'           #" << std::endl;
    outfile << "#####P'                    ,#################P'             #" << std::endl;
    outfile << "###P'                      d##############P''               #" << std::endl;
    outfile << "##P'                       V##############'                 #" << std::endl;
    outfile << "#P'                         `V###########'                  #" << std::endl;
    outfile << "#'                             `V##P'                       #" << std::endl;
    outfile << "_____________________________________________________________" << std::endl;
    outfile << "#############################################################" << std::endl;
    outfile.close();
}


void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if ((this->getSignature() == false) ||  (executor.getGrade() > this->getExGrade()))
        throw GradeTooLowException();
    CreateShrubbery(_target);
    std::cout << "√: " << this->getName() << " executed successfully" << std::endl; 
}
