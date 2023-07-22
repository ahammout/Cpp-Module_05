/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:08:16 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/22 14:22:50 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/AForm.hpp"

///@param constructures needs to to take the attributes to initialize, in the derived classes need to call the parametred constructor.

AForm::AForm() : _name("Shahdat sokna"), _signature(false), _sgrade(1), _exgrade(5)
{
    std::cout << "Form: " << _name << " default constructor called" << std::endl;
}

AForm::AForm(std::string n, bool _si, int _sg, int _exg): _name(n), _signature(_si), _sgrade(_sg), _exgrade(_exg)
{
    std::cout << "Form: " << _name << " parametered constructor called" << std::endl;
    if (_si > 150 || _exg > 150)
        throw GradeTooLowException();
    if (_si < 1 || _exg < 1)
        throw GradeTooHighException();
}

AForm::~AForm()
{
    std::cout << "Form: " << _name << " destructor called" << std::endl;
}

AForm::AForm(AForm &SRC): _name(SRC._name), _signature(SRC._signature), _sgrade(SRC._sgrade), _exgrade(SRC._exgrade)
{
    std::cout << "Form: " << _name << " copy constructor called" << std::endl;
    *this = SRC;
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
}

std::ostream    &operator<<(std::ostream &output, AForm &REF)
{
    output << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}
