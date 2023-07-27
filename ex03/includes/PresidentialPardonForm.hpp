/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:41:55 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 21:12:55 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include<iostream>
#include"AForm.hpp"
#include"Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    private:
    std::string _target;

    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    PresidentialPardonForm(PresidentialPardonForm &SRC);
    
    class GradeTooLowException : std::exception
    {
        public:
        const char* what() const throw();
    };

    PresidentialPardonForm  &operator=(PresidentialPardonForm &RightHand);

    std::string getTarget() const;

    void    execute(Bureaucrat const &executor ) const;
};

std::ostream &operator<<(std::ostream &output, PresidentialPardonForm &REF);

#endif