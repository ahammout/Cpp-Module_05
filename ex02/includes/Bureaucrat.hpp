/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:58:22 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/24 19:11:42 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include"AForm.hpp"

///@note  every bureaucrat needs to sign a form there is new rules for bureaucrates, so there is more job !!


class AForm;
class   Bureaucrat
{
    private:
    const std::string   name;
    int grade;

    public:
    Bureaucrat();
    Bureaucrat(int gr, std::string n);
    ~Bureaucrat();

    Bureaucrat(Bureaucrat &SRC);
    Bureaucrat  &operator=(Bureaucrat &RightHand);
    class   GradeTooHighException : std::exception
    {
        public:
        const char* what() const throw();
    };
    class   GradeTooLowException : std::exception
    {
        public:
        const char* what() const throw();
    };
    int                 getGrade();
    const std::string   getName();
    void                incrGrade();
    void                decrGrade();

    void    signForm();
};

std::ostream &operator<<(std::ostream &output, Bureaucrat &REF);

#endif