/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:11:05 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 21:37:24 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Intern.hpp"
#include"../includes/ShrubberyCreationForm.hpp"
#include"../includes/RobotomyRequestForm.hpp"
#include"../includes/PresidentialPardonForm.hpp"
#include"../includes/AForm.hpp"

//---***------------------------------------- CONSTRUCTORS ---------------------------------***---//

Intern::Intern()
{
    std::cout << "▷ Intern default constructor called" << std::endl;
}

Intern::Intern(Intern &SRC)
{
    std::cout << "▷ Copy constructor called" << std::endl;
    *this = SRC;
}

Intern::~Intern(){
    std::cout << "◁ Intern Destructor called" << std::endl;
}

//---***------------------------------------- OVERLOADING OPERATORS ---------------------------------***---//

Intern& Intern::operator=(Intern &RightHand)
{
    (void) RightHand;
    return (*this);
}

//---***------------------------------ EXCEPTION METHODS --------------------------***---//

const char *Intern::FormNotExist::what() const throw()
{
    return ("╳: Form name doesn't exist");
}

//---***------------------------------ INTERN METHODS --------------------------***---//

void    deleteForms(AForm *Forms[], int j)
{
    for (int i=0;i < 3;i++)
    {   
        if (i == j)
            continue;
        delete Forms[i];
    }
}

AForm*  Intern::makeForm(std::string FormName, std::string TargetName)
{
    std::string FormNames[3] = { "robotomy request", "president request", "shrubbery request"};
    AForm*  Forms[3] = {new RobotomyRequestForm(TargetName), new PresidentialPardonForm(TargetName), new ShrubberyCreationForm(TargetName)};
    int i = 0;

    while (i < 4)
    {
        if (FormNames[i].compare(FormName) == 0)
        {
            std::cout << "√: Intern creates " << FormName << std::endl;
            deleteForms(Forms, i);
            return (Forms[i]);
        }
        i++;
    }
    deleteForms(Forms, 8);
    throw FormNotExist();
    return (NULL);
}