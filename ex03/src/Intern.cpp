/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:11:05 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/26 17:57:57 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Intern.hpp"

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

AForm*  Intern::makeForm(std::string FormName, std::string TargetName)
{
    
}