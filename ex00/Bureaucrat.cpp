/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:03:28 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/19 15:39:42 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    this->name = "fortoto";
    this->grade = 150;
    std::cout << "Bureaucrat: " << this->name << " default constructor called" << std::endl;
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
    this->grade = RightHand.getGrade();
    this->name = RightHand.getName();
    return(*this);
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
        throw   -1;
}

/// @brief check if The Grade attr is able to be inctement
/// @return throw an exeption if grade is out of the range
/// @exception Bureaucrat::GradeTooLowException ==> this class inherates from exeption parent class
void    Bureaucrat::decrGrade()
{
    std::cout << "decrement grade function called" << std::endl;
    grade++;
    if (grade > 150)
        throw -2;
}