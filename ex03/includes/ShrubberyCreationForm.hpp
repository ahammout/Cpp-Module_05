/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:59:34 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 21:19:09 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include<iostream>
#include<fstream>
#include"AForm.hpp"
#include"Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
    std::string _target;

    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(ShrubberyCreationForm &SRC);

    ShrubberyCreationForm   &operator=(ShrubberyCreationForm &RightHand);

    std::string getTarget() const;

    class GradeTooLowException : std::exception
    {
        public:
        const char* what() const throw();
    };
    
    void    execute(Bureaucrat const & executor) const;
    void    CreateShrubbery(std::string target) const;
};

std::ostream    &operator<<(std::ostream &output, ShrubberyCreationForm &REF);

#endif