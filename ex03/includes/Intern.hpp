/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:25 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 16:18:41 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include<iostream>
#include"AForm.hpp"

class   Intern
{
    public:
    Intern();
    Intern(Intern  &SRC);
    ~Intern();
    
    Intern& operator=(Intern &RightHand);
    
    AForm   *makeForm(std::string FornName, std::string TargetName);
    class FormNotExist : std::exception
    {
        public:
        const char* what() const throw();
    };
};

#endif