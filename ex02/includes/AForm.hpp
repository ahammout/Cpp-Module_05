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
    std::string getName() const;
    bool    getSignature() const;
    int getSgrade() const;
    int getExGrade() const;

    //----------- SETTERS -----------------/
    ///@note Set attributes using the prametered constructor
    // void    setName(const std::string name);
    // void    setSignature(bool signature);
    // void    setSgrade(const int sgrade);
    // void    setExGrade(const int exgrade);

    //---------- PURE VIRTUAL FUNCTION -------------/ 
    virtual void    beSigned(Bureaucrat &B);
};

std::ostream    &operator<<(std::ostream &output, AForm &REF);

#endif