/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:56:37 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/25 15:56:44 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ShrubberyCreationForm.hpp"

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

ShrubberyCreationForm&  