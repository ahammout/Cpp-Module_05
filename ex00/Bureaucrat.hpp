/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:53:17 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/17 18:04:17 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
class   Bureaucrat
{
    private:
    const std::string   name;
    int grade;

    public:
    Bureaucrat();
    ~Bureaucrat();

    Bureaucrat(Bureaucrat &SRC);
    Bureaucrat  &operator=(Bureaucrat &RightHand);


    int                 getGrade();
    const std::string   getName();
    
};

#endif