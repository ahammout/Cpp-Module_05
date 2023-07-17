/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:57:56 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/24 18:20:37 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Aghir m9adam"), grade(150)
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

Bureaucrat::Bureaucrat(Bureaucrat &SRC): name("Lm9adam")
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
    return ("Exception: Bureaucrat grade is to high");
}

const char*    Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exception: Bureaucrat grade is too low");

}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

const   std::string Bureaucrat::getName()
{
    return (this->name);
}

void    Bureaucrat::incrGrade()
{
    std::cout << "Increment grade function called" << std::endl;
    grade--;
    if (grade <= 0)
        throw   GradeTooHighException();
}

void    Bureaucrat::decrGrade()
{
    std::cout << "decrement grade function called" << std::endl;
    grade++;
    if (grade > 150)
        throw   GradeTooLowException();
}

void    Bureaucrat::signForm()
{
    AForm *formObj = NULL;

    try
    {
        formObj->beSigned(*this);
        std::cout << this->getName() << " Signed " << formObj->getName() << std::endl;
    }
    catch (AForm::GradeTooLowException &ex)
    {
        std::cerr << this->getName() << " couldn't sign " << formObj->getName() << " because his grade is too low!" << std::endl;
    }
    catch (...)
    {
        std::cerr << "Exception: unexpected exception" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, Bureaucrat &REF)
{
    output << REF.getName() << " bureaucrat grade " << REF.getGrade();
    return (output);
}