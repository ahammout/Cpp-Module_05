/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:11:05 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/26 18:47:32 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Intern.hpp"
#include"../includes/ShrubberyCreationForm.hpp"
#include"../includes/RobotomyRequestForm.hpp"
#include"../includes/PresidentialPardonForm.hpp"

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
    this->silent = RightHand.getSilent();
    return (*this);
}

//---***------------------------------ GETTERS --------------------------***---//

int    Intern::getSilent()
{
    return (silent);
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
*/

AForm*  Intern::makeForm(std::string FormName, std::string TargetName)
{
    int i = 0;
    std::string FormNames[3] = { "robotomy request",
                                 "President request",
                                 "Shrubbery request"};

    while (i <= 4)
    {
        if (FormNames[i].compare(FormName) == 0)
    }
}