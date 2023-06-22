/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:50:12 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/22 18:38:57 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include"Bureaucrat.hpp"

class Bureaucrat;
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
    Form&   operator=(const Form &RightHand);

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

    std::string getName() const;
    bool    getSignature() const;
    int getSgrade() const;
    int getExGrade() const;

    void    beSigned(Bureaucrat &B);
};

std::ostream    &operator<<(std::ostream &output, Form &REF);

#endif