/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:25 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/26 17:16:02 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include<iostream>
#include"AForm.hpp"

class   Intern
{
    private:
    int silent;

    public:
    Intern();
    Intern(Intern  &SRC);
    ~Intern();
    
    int getSilent();
    Intern& operator=(Intern &RightHand);
    
    AForm   *makeForm(std::string FornName, std::string TargetName); 
};

#endif