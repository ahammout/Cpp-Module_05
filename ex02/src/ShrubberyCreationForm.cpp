/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:56:37 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/25 18:32:39 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ShrubberyCreationForm.hpp"

//---***------------------------------------- CONSTRUCTORS ---------------------------------***---//

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137)
{
    std::cout << this->getName() << " Default constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = "DefaultTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137)
{
    std::cout << this->getName() << " Parametred constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << this->getName() << " Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &SRC) : AForm(SRC.getName(), SRC.getSignature(), SRC.getExGrade(), SRC.getSgrade())
{
    std::cout << this->getName() << " Copy constructor called" << std::endl;
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
    output << REF.getTarget() << std::endl << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}

//---***------------------------------ OVERLOADING EXCEPTION METHODS --------------------------***---//

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
    return (" Can't execute the form because his grade is low!");
}

//---***------------------------------ GETTERS --------------------------***---//

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

//---***------------------------------ SHRUBBERYCREATIONFORM METHODS --------------------------***---//

    ///@brief The function to execute the form
    //-- Creating a file named <target>_shrubbery and copy the ASCCI tree to it.
    ///@note Open the file to read from it,
    // create a new file with name [target]_shrubbery and transform the data of the file to it.
    // open file with ap 
    
void    ShrubberyCreationForm::CreateShrubbery(std::string target) const
{
    std::fstream infile;
    std::fstream outfile;
    std::string filename;
    std::string tmp;

    infile.open("AsciiTree", std::ios_base::in);
    if (!infile.is_open())
    {
        std::cout << "╳: Error: can't open the file" << std::endl;
        exit(0);
    }
    filename = target;
    filename.append("_shrubbery");
    outfile.open(filename, std::ios_base::out);
    if (!outfile.is_open())
    {
        std::cout << "╳: Error: can't open the file" << std::endl;
        exit(0);
    }
    while (getline(infile, tmp, '\0'))
    {
        outfile << tmp;
        tmp.erase();
    }
    infile.close();
    outfile.close();
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if ((this->getSignature() == false) ||  (executor.getGrade() > this->getExGrade()))
        throw GradeTooLowException();
    CreateShrubbery(_target);
    std::cout << "√: " << this->getName() << " executed successfully" << std::endl; 
}
///@note method execute.
