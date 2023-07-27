/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:25:49 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 21:13:08 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include<iostream>
#include"AForm.hpp"
#include"Bureaucrat.hpp"

class   RobotomyRequestForm : public AForm
{
    private:
    std::string _target;

    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();

    RobotomyRequestForm(RobotomyRequestForm &SRC);

    class GradeTooLowException : std::exception
    {
        public:
        const char* what() const throw();
    };

    RobotomyRequestForm &operator=(RobotomyRequestForm &RightHand);

    std::string getTarget() const;

    void    execute(Bureaucrat const &executor ) const;
};

std::ostream &operator<<(std::ostream &output, RobotomyRequestForm &REF);

#endif