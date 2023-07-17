/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:50:17 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/22 18:40:12 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Form.hpp"

Form::Form() : _name("Shahdat sokna"), _signature(false), _sgrade(1), _exgrade(5)
{   
    std::cout << "Form: " << _name << " default constructor called" << std::endl;
}

Form::Form(std::string n, bool _si, int _sg, int _exg): _name(n), _signature(_si), _sgrade(_sg), _exgrade(_exg)
{
    std::cout << "Form: " << _name << " parametered constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form: " << _name << " destructor called" << std::endl;
}

Form::Form(Form &SRC): _name(SRC._name), _signature(SRC._signature), _sgrade(SRC._sgrade), _exgrade(SRC._exgrade)
{
    std::cout << "Form: " << _name << " copy constructor called" << std::endl;
    *this = SRC;
}

Form&   Form::operator=(const Form &RightHand)
{
    Form(RightHand._name, RightHand._signature, RightHand._sgrade, RightHand._exgrade);
    return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::string    Form::getName() const
{
    return(this->_name);
}

bool    Form::getSignature() const
{
    return (this->_signature);
}

int   Form::getSgrade() const
{
    return (this->_sgrade);
}

int   Form::getExGrade() const
{
    return (this->_exgrade);
}

void    Form::beSigned(Bureaucrat &B)
{
    if (B.getGrade() > this->getSgrade())
        throw GradeTooLowException();
    this->_signature = true;
}

std::ostream    &operator<<(std::ostream &output, Form &REF)
{
    output << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}
