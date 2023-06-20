/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:50:17 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/20 19:38:02 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Form.hpp"

Form::Form() : _signature(false), _name("Shahdat sokna"), _sgrade(1), _exgrade(5)
{   
    std::cout << "Form: " << _name << " default constructor called" << std::endl;
    // if (Bureaucrat::getGrade > _sgrade)
    //     throw GradeTooLowException();
    // if (Bureaucrat::getGrade() < _sgrade)
    //     throw GradeTooHighException();
}

Form::Form(std::string n, bool _si, int _sg, int _exg): _name(n), _signature(_si), _sgrade(_sg), _exgrade(_exg)
{
    std::cout << "Form: " << _name << " parametered constructor called" << std::endl;
}