/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:53:17 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/20 19:22:27 by ahammout         ###   ########.fr       */
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
    
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &REF);

#endif