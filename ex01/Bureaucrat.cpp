/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:03:28 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/21 19:43:37 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("l3amel"), grade(150)
{
    std::cout << "Bureaucrat: " << this->name << " default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int gr, std::string n) : name(n), grade(gr)
{
    std::cout << "Bureaucrat: " << this->name << " parametered constructor called" << std::endl;
    if (gr <= 0)
        throw   GradeTooHighException();
    if (gr > 150)
        throw   GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: " << this->name << " destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &SRC)
{
    std::cout << "Bureaucrat: " << this->name << " copy constructor called" << std::endl;
    *this = SRC;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &RightHand)
{
    if (RightHand.getGrade() <= 0)
        throw   GradeTooHighException();
    if (RightHand.getGrade() > 150)
        throw   GradeTooLowException();
    this->grade = RightHand.getGrade();
    return(*this);
}

const char*     Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade is to high");
}

const char*    Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade is too low");

}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

const   std::string Bureaucrat::getName()
{
    return (this->name);
}

/// @brief check if The Grade attr is able to be inctement
/// @return throw an exeption if grade is out of the range
/// @exception Bureaucrat::GradeTooHighException ==> this class inherates from exeption parent class
void    Bureaucrat::incrGrade()
{
    std::cout << "Increment grade function called" << std::endl;
    grade--;
    if (grade <= 0)
        throw   GradeTooHighException();
}

/// @brief check if The Grade attr is able to be inctement
/// @return throw an exeption if grade is out of the range
/// @exception Bureaucrat::GradeTooLowException ==> this class inherates from exeption parent class
void    Bureaucrat::decrGrade()
{
    std::cout << "decrement grade function called" << std::endl;
    grade++;
    if (grade > 150)
        throw   GradeTooLowException();
}

void    Bureaucrat::signForm()
{
    Form formObj;

    try
    {
        formObj.beSigned(*this);
        std::cout << this->getName() << " Signed " << formObj.getName() << std::endl;
    }
    catch (Form::GradeTooLowException &ex)
    {
        std::cout << this->getName() << " couldn't sign " << formObj.getName() << " because Bureaucrat grade is too low!" << std::endl;
    }
    catch (...)
    {
        std::cout << "Exception: unexpected exception" << std::endl;
    }
}
// <name>, bureaucrat grade <grade>.

std::ostream &operator<<(std::ostream &output, Bureaucrat &REF)
{
    output << REF.getName() << " bureaucrat grade " << REF.getGrade();
    return (output);
}