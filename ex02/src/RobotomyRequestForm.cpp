/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:49:15 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/25 20:51:15 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/RobotomyRequestForm.hpp"

//---***------------------------------------- CONSTRUCTORS ---------------------------------***---//

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", false, 72, 45)
{
    std::cout << this->getName() << " Default constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = "DefaultTarget";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45)
{
    std::cout << this->getName() << " Parametred constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << this->getName() << " Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &SRC)
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

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm &RightHand)
{
    RobotomyRequestForm(RightHand.getTarget());
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, RobotomyRequestForm &REF)
{
    output << REF.getTarget() << std::endl << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}

//---***------------------------------ OVERLOADING EXCEPTION METHODS --------------------------***---//

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
    return (" couldn't robotomize beacause his grade is low!");
}

//---***------------------------------ GETTERS --------------------------***---//

std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

//---***------------------------------ ROBOTOMYREQUESTFORM METHODS --------------------------***---//

void    RobotomyRequestForm::execute(Bureaucrat const &executor ) const
{
    if ((this->getSignature() == false) || (executor.getGrade() > this->getExGrade()))
        throw GradeTooLowException();
    std::cout << "√: " << this->getTarget() << " has been robotomized successfully 50% of the time!" << std::endl; 

}
