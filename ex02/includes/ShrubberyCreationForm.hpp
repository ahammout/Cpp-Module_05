/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:59:34 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/22 18:07:34 by ahammout         ###   ########.fr       */
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
    private:
    std::string _target;

    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(ShrubberyCreationForm &SRC);

    ShrubberyCreationForm   &operator=(ShrubberyCreationForm &RightHand);

    std::string getTarget();
    
    ///@Method function to execute the form.
};

std::ostream    &operator<<(std::ostream &output, ShrubberyCreationForm &REF);

#endif