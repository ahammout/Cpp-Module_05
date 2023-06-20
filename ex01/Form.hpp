/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:50:12 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/21 00:06:31 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include"Bureaucrat.hpp"

class   Form 
{
    private:
    const std::string _name;
    bool    _signature;
    const int   _sgrade;
    const int   _exgrade;

    public:
    Form();
    Form(std::string n, bool _si, int _sg, int _exg);
    ~Form();

    Form(Form &SRC);
    Form&   operator=(Form &RgihtHand);

    class GradeTooHighException : std::exception
    {
        public:
        const char* what() const throw();
    };
    class GradeTooLowException : std::exception
    {
        public:
        const char* what() const throw();
    };

    const std::string getName();
    bool    getSignature();
    const int getSgrade();
    const int getExGrade();

    void    beSigned(Bureaucrat &B);
    void    signForm(Bureaucrat &B);
};

std::ostream    &operator<<(std::ostream &output, Form &REF);

#endif