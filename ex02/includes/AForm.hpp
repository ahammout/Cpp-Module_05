/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:37:33 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/24 19:10:20 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include<iostream>
#include"Bureaucrat.hpp"

///@note This is an abstract class, this class can not be intentiated, this is an abstract base class, it will the base class of the other forms derived classes.

class Bureaucrat;
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
    AForm&   operator=(const AForm &RightHand);

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

    //----------- GETTERS ----------------/
    ///@note getters don't need to be implemented in the derived class: They don't have spevific effect in derived class
    std::string getName() const;
    bool    getSignature() const;
    int getSgrade() const;
    int getExGrade() const;

    //---------- ADDITIONAL FUNCTIONS -------------/ 
    void    beSigned(Bureaucrat &B);
};

std::ostream    &operator<<(std::ostream &output, AForm &REF);

#endif