/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:08:16 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/25 18:54:32 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/AForm.hpp"

//---***------------------------------------- CONSTRUCTORS ---------------------------------***---//

AForm::AForm() : _name("DefaultForm"), _signature(false), _sgrade(1), _exgrade(5)
{
    std::cout << "AForm " << "default constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
}

AForm::AForm(const std::string n, bool _si, int _sg, int _exg): _name(n), _signature(_si), _sgrade(_sg), _exgrade(_exg)
{
    std::cout << "AForm " << "parametered constructor called" << std::endl;
    if (this->getSgrade() > 150 || this->getExGrade() > 150)
        throw GradeTooLowException();
    if (this->getSgrade() < 1 || this->getExGrade() < 1)
        throw GradeTooHighException();
}

AForm::~AForm()
{
    std::cout << "AForm " << "destructor called" << std::endl;
}

AForm::AForm(AForm &SRC): _name(SRC._name), _signature(SRC._signature), _sgrade(SRC._sgrade), _exgrade(SRC._exgrade)
{
    std::cout << "AForm "<< "copy constructor called" << std::endl;
    *this = SRC;
}

//---***------------------------------------- OVERLOADING OPERATORS ---------------------------------***---//

AForm&  AForm::operator=(const AForm &RightHand)
{
    std::string B;
    
    B = RightHand.getName();
    return (*this);
}

std::ostream    &operator<<(std::ostream &output, AForm &REF)
{
    output << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

//---***------------------------------ GETTERS --------------------------***---//

std::string    AForm::getName() const
{
    return(this->_name);
}

bool    AForm::getSignature() const
{
    return (this->_signature);
}

int   AForm::getSgrade() const
{
    return (this->_sgrade);
}

int   AForm::getExGrade() const
{
    return (this->_exgrade);
}

//---***------------------------------ AFORM METHODS --------------------------***---//

void    AForm::beSigned(Bureaucrat &B)
{
    if (B.getGrade() > this->getSgrade())
        throw GradeTooLowException();
    this->_signature = true;
}

void    AForm::execute(Bureaucrat const & executor) const
{
    if ((this->getSignature() == false) && (executor.getGrade() > this->getExGrade()))
        throw GradeTooLowException();
    std::cout << "√: Form Executed" << std::endl;
}
