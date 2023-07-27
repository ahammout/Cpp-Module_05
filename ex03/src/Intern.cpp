/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:11:05 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 16:28:47 by ahammout         ###   ########.fr       */
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

//---***------------------------------ INTERN METHODS --------------------------***---//

///@brief This method will take a norm name as a parameter and it's target, it will init init the attribute of the specific
/// class passed to it as parameter and it will return an instence object from the specified class.
///! The problem here is that there is no need to use the if/else statements to check which constructor class needs  to call 
///! create an instence from it and return it
/*
    * first we know that there is three classes to instence from them and a base class which the AForm class, so the input can
    * be between three possible classes name:  PresidentialPardonForm and RobotomyRequestForm and ShrubberyCreationForm 
    * so there is specific names to be passed to the function parameter, then need an array of strings and put all the possible Form Names inside it
    * and compare them with the parameter passed to the method.
    ! If the name passed as parameter doesn't exist, print an explicit error message
    * Now to handle the returns cases withoud using if/else forest needs to declare an array of form objects, then return it after comparing the name passed as param
    * With the name inside the array, to return the appropriat object will use the same index of the array of strings. 
    ! Needs to free the array of form objects.
*/
void    deleteForms(AForm *Forms[], int j)
{
    for (int i=0;i < 3;i++)
    {   
        if (i == j)
            continue;
        delete Forms[i];
    }
}

const char *Intern::FormNotExist::what() const throw()
{
    return ("╳: Form name doesn't exist");
}

AForm*  Intern::makeForm(std::string FormName, std::string TargetName)
{
    std::string FormNames[3] = { "robotomy request", "President request", "Shrubbery request"};
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