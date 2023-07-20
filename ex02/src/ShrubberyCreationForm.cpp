/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:56:37 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/20 19:19:15 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ShrubberyCreationForm.hpp"

///@note Begin implementing the methods  of the CLASS ShrubberyCreationForm 

ShrubberyCreationForm::ShrubberyCreationForm()
{
    // INIT ALL THE CLASS ATTRIBUTE
    AForm();
    std::cout << "Form: " << getName() << " default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string n, bool _sign, int _sg, int _exg)
{
    AForm(n, _sign, _sg, _exg);
    std::cout << "Form: " << getName() << " parametred constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Form: " << getName() << " destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & SRC): AForm(SRC.getName(), SRC.getSignature(), SRC.getSgrade(), SRC.getExGrade())
{
    std::cout << "Form: " << getName() << " copy constructor called" << std::endl;
    *this = SRC;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm &RightHand)
{
    AForm (RightHand.getName(), RightHand.getSignature(), RightHand.getSgrade(), RightHand.getExGrade());
    return (*this);
}

// //---------------------------------------------- SETTERS ----------------------------------------/

// void    ShrubberyCreationForm::setName(const std::string name)
// {
//     this->_name = name;
// }

// void    ShrubberyCreationForm::setSignature(bool signature)
// {
//     this->_signature = signature;
// }

// void    ShrubberyCreationForm::setSgrade(const int sgrade)
// {
//     this->_sgrade = sgrade;
// }

// void    ShrubberyCreationForm::setExgrade(const int exgrade)
// {
//     this->_exgrade = exgrade;
// }

void    ShrubberyCreationForm::beSigned(Bureaucrat &B)
{
    if (B.getGrade() > this->getSgrade())
        throw GradeTooLowException();
    this->_signature = true;
}

void    ShrubberyCreationForm::beSigned(Bureaucrat &B)
{
    ///@note check if the bureaucrat have the possible sign grade to sign the form;
    if (B.getGrade() > this->getSgrade())
        throw GradeTooLowException;
    this->_signature = true;
}
//---------------------------------------------- OVERLOAD OPERATOR ----------------------------------------/

std::ostream&   operator<<(std::ostream &output, ShrubberyCreationForm &REF)
{
    output << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}