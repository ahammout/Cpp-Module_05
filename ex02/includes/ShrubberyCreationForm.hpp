/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:59:34 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/24 18:05:40 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include<iostream>
#include"AForm.hpp"
#include"Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string _n, bool _sign, int _sg, int _exg);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(ShrubberyCreationForm &SRC);

    ShrubberyCreationForm   &operator=(ShrubberyCreationForm &RightHand);

    void    besigned(Bureaucrat &B);
};

#endif