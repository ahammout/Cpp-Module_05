/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:41:57 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 21:39:03 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/PresidentialPardonForm.hpp"

//---***------------------------------------- CONSTRUCTORS ---------------------------------***---//

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5)
{
    std::cout << "▷ " << this->getName() << " Default constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = "Random Target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5)
{
    std::cout << "▷ " << this->getName() << " Parametred constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "◁ " << this->getName() << " Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &SRC)
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

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &RightHand)
{
    PresidentialPardonForm(RightHand.getTarget());
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, PresidentialPardonForm &REF)
{
    output << "▮▮▶ name ▶ " << REF.getName() << "\n    Signature ▶ " <<  REF.getSignature() << "\n    Sign grade ▶ " << REF.getSgrade() << "\n    Execute grade ▶ " << REF.getExGrade() << std::endl;
    return (output);
}

//---***------------------------------ EXCEPTION METHODS --------------------------***---//

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
    return (" can't pardon because his grade is low!");
}

//---***------------------------------ GETTERS --------------------------***---//

std::string PresidentialPardonForm::getTarget() const
{
    return (_target);
}

//---***------------------------------ ROBOTOMYREQUESTFORM METHODS --------------------------***---//

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if ((this->getSignature() == false) || (executor.getGrade() > this->getExGrade()))
        throw GradeTooLowException();
    std::cout << "√: " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl; 
}