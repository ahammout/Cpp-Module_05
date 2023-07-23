/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:08:16 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/23 15:27:03 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/AForm.hpp"

///@param constructures needs to to take the attributes to initialize, in the derived classes need to call the parametred constructor.

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

AForm&  AForm::operator=(const AForm &RightHand)
{
    std::string B;
    
    B = RightHand.getName();
    return (*this);
}

//------------------------------- EXEPTIONS METHODS ----------------------------/

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

//------------------------------------------------- GETTERS ---------------------------------------------------/

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

void    AForm::beSigned(Bureaucrat &B)
{
    if (B.getGrade() > this->getSgrade())
        throw GradeTooHighException();
    this->_signature = true;
    std::cout << "B has signed the form" << std::endl;
}

std::ostream    &operator<<(std::ostream &output, AForm &REF)
{
    output << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}
