/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:59:34 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/20 19:19:20 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include<iostream>
#include"AForm.hpp"
#include"Bureaucrat.hpp"

///@note Begin Declaring the derived CLASS ShrubberyCreationForm 

class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string _n, bool _sign, int _sg, int _exg);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(ShrubberyCreationForm &SRC);

    ShrubberyCreationForm   &operator=(ShrubberyCreationForm &RightHand);

    // ///@b Derived_implementation Implement setters for derived class
    // void    setName(const std::string name);
    // void    setSignature(bool signature);
    // void    setSgrade(const int sgrade);
    // void    setExgrade(const int exgrade);
    
    void    beSigned(Bureaucrat &B);
};

std::ostream    &operator<<(std::ostream &output, AForm &REF);

#endif