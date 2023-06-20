/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:50:17 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/21 00:10:37 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Form.hpp"

Form::Form() : _signature(false), _name("Shahdat sokna"), _sgrade(1), _exgrade(5)
{   
    std::cout << "Form: " << _name << " default constructor called" << std::endl;
    // if (Bureaucrat::getGrade > _sgrade)
    //     throw GradeTooLowException();
    // if (Bureaucrat::getGrade() < _sgrade)
    //     throw GradeTooHighException();
}

Form::Form(std::string n, bool _si, int _sg, int _exg): _name(n), _signature(_si), _sgrade(_sg), _exgrade(_exg)
{
    std::cout << "Form: " << _name << " parametered constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form: " << _name << " destructor called" << std::endl;
}

Form::Form(Form &SRC)
{
    std::cout << "Form: " << _name << " copy constructor called" << std::endl;
    *this = SRC;
}

Form&   Form::operator=(Form &RightHand)
{
    this->_name = RightHand.getName();
    this->_signature = RightHand.getSignature();
    this->_exgrade = RightHand.getExGrade();
    this->_sgrade = RightHand.getSgrade();
    return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    std::cout << "Grade is too high" << std::endl;
}

const char* Form::GradeTooLowException::what() const throw()
{
    std::cout << "Grade is too low" << std::endl;
}

const std::string    Form::getName()
{
    return(this->_name);
}

bool    Form::getSignature()
{
    return (this->_signature);
}

const int   Form::getSgrade()
{
    return (this->_sgrade);
}

const int   Form::getExGrade()
{
    return (this->_exgrade);
}

std::ostream    &operator<<(std::ostream &output, Form &REF)
{
    output << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}

void    Form::beSigned(Bureaucrat &B)
{
    if (B.getGrade() > this->getSgrade())
        throw GradeTooLowException();
    this->_signature = true;
}