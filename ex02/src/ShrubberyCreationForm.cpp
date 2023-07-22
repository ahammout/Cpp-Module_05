/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:56:37 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/22 18:35:51 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 5, 2)
{
    std::cout << this->getName() << " Default constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = "DefaultTarget";
    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 5, 2)
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

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm &RightHand)
{
    ///@note Add Some shit here and rem you are in the derived class.
    ///@param initialization init attr using constructors NOT Working.
    // AForm(RightHand.getName(), RightHand.getSignature(), RightHand.getSgrade(), RightHand.getExGrade());
    ShrubberyCreationForm(RightHand._target);
    return (*this);
}

std::string ShrubberyCreationForm::getTarget()
{
    return (_target);
}

std::ostream    &operator<<(std::ostream &output, ShrubberyCreationForm &REF)
{
    output << REF.getTarget() << std::endl << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}

///@note method execute.
