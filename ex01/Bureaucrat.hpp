/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:53:17 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/21 00:15:44 by ahammout         ###   ########.fr       */
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

    ///@note  Add member function signForm() that will call the member function beSigned() of the the class Form to sign it if the grade is high enough;
    
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &REF);

#endif