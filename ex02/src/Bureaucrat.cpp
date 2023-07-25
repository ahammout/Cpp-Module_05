/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:57:56 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/25 23:27:16 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"


//---***------------------------------------- CONSTRUCTORS ---------------------------------***---//

Bureaucrat::Bureaucrat() : name("Aghir m9adam"), grade(150)
{
    std::cout << "▷ Bureaucrat: " << this->name << " default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int gr, std::string n) : name(n), grade(gr)
{
    std::cout << "▷ Bureaucrat: " << this->name << " parametered constructor called" << std::endl;
    if (gr <= 0)
        throw   GradeTooHighException();
    if (gr > 150)
        throw   GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "◁ Bureaucrat: " << this->name << " destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &SRC): name("Lm9adam")
{
    std::cout << "▷ Bureaucrat: " << this->name << " copy constructor called" << std::endl;
    *this = SRC;
}

//---***------------------------------------- OVERLOADING OPERATORS ---------------------------------***---//

Bureaucrat& Bureaucrat::operator=(Bureaucrat &RightHand)
{
    if (RightHand.getGrade() <= 0)
        throw   GradeTooHighException();
    if (RightHand.getGrade() > 150)
        throw   GradeTooLowException();
    this->grade = RightHand.getGrade();
    return(*this);
}

std::ostream &operator<<(std::ostream &output, Bureaucrat &REF)
{
    output << "▶▶ "<< REF.getName() << " bureaucrat grade " << REF.getGrade() << std::endl;
    return (output);
}

//---***------------------------------ OVERLOADING EXCEPTION METHODS --------------------------***---//

const char*     Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("╳: Bureaucrat grade is to high");
}

const char*    Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("╳: Bureaucrat grade is too low");

}

//---***------------------------------ GETTERS --------------------------***---//

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

const   std::string Bureaucrat::getName() const
{
    return (this->name);
}

//---***------------------------------ BUREAUCRAT METHODS --------------------------***---//

void    Bureaucrat::incrGrade()
{
    grade--;
    if (grade <= 0)
        throw   GradeTooHighException();
}

void    Bureaucrat::decrGrade()
{
    grade++;
    if (grade > 150)
        throw   GradeTooLowException();
}

///@note make this function take a const reference to AForm derived object.
///@ref need to test it.
void    Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "√: " << this->getName() << " Signed " << form.getName() <<std::endl;
    }
    catch (const AForm::GradeTooLowException &ex)
    {
        std::cerr << "╳: " << this->getName() << " couldn't sign " << form.getName() << " because his grade is low!" <<std::endl;
    }
    catch (...)
    {
        std::cerr << "╳: unexpected error " << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
    }
    ///@ref need to implement the what() method exception for all the derived classes.
    catch (AForm::GradeTooLowException &ex)
    {
        std::cout << "╳: " << this->getName() << ex.what() << std::endl;
    }
    catch (ShrubberyCreationForm::GradeTooLowException &ex)
    {
        std::cout << "╳: " << this->getName() << ex.what() << std::endl;
    }
    catch (RobotomyRequestForm::GradeTooLowException &ex)
    {
        std::cout <<  "╳: " << this->getName() << ex.what() << std::endl;
    }
    catch (PresidentialPardonForm::GradeTooLowException &ex)
    {
        std::cout <<  "╳: " << this->getName() << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "╳: unexpected error" << std::endl;
    }
}
