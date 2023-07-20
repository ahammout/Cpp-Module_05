/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:37:33 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/20 19:01:34 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include<iostream>
#include"Bureaucrat.hpp"

class Bureaucrat;

///@b Brief Make this class an abstract class
class   AForm 
{
    private:
    const std::string _name;
    bool    _signature;
    const int   _sgrade;
    const int   _exgrade;

    public:
    AForm();
    AForm(std::string n, bool _si, int _sg, int _exg);
    ~AForm();

    AForm(AForm &SRC);
    virtual AForm&   operator=(const AForm &RightHand) = 0;

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

    virtual void    beSigned(Bureaucrat &B) = 0;
};

std::ostream    &operator<<(std::ostream &output, AForm &REF);

#endif