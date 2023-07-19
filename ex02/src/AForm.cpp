/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:08:16 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/24 19:10:03 by ahammout         ###   ########.fr       */
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

AForm&   AForm::operator=(const AForm &RightHand)
{
    ///@note Can not init usign the constructor, it will be a bad idea.
    ///@p setters to set attributes, "problem with overloading op="
    _name = RightHand._name;
    // AForm(RightHand._name, RightHand._signature, RightHand._sgrade, RightHand._exgrade);
    return (*this);
}

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

// //------------------------------------------------- SETTERS ---------------------------------------------------/

// void    AForm::setName(std::string name)
// {
//     _name = name;
// }
// void    AForm::setSignature(bool signature)
// {
//     _signature = signature;
// }
// void    AForm::setSgrade(const int sgrade)
// {
//     _sgrade = sgrade;
// }
// void    AForm::setExGrade(const int exgrade)
// {
//     _exgrade = exgrade;
// }

//---------------------------------------------- ADDITIONAL FUNCTIONS ----------------------------------------/

void    AForm::beSigned(Bureaucrat &B)
{
    if (B.getGrade() > this->getSgrade())
        throw GradeTooLowException();
    this->_signature = true;
}

//---------------------------------------------- OVERLOAD OPERATOR ----------------------------------------/

std::ostream    &operator<<(std::ostream &output, AForm &REF)
{
    output << REF.getName() << std::endl <<  REF.getSignature() << std::endl << REF.getExGrade() << std::endl << REF.getSgrade() << std::endl;
    return (output);
}
