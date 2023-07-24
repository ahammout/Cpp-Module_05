/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:25:49 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/24 21:30:07 by ahammout         ###   ########.fr       */
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

    RobotomyRequestForm &operator=(RobotomyRequestForm &RightHand);

    std::string getTarget();

    void    execute(Bureaucrat const &executor )
}

#endif