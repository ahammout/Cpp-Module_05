/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/20 18:24:31 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

int main (void)
{
    Bureaucrat obj;
    
    // std::cout <<  obj.getGrade() << std::endl;
    try
    {
        std::cout <<  obj << std::endl;
        /// test with copy constrctor copy assignment operator
        // obj = Bureaucrat(190);
        obj.decrGrade();
    }
    ///@param const std::exception& ex
    ///@note add more tests
    catch(Bureaucrat::GradeTooHighException ex)
    {
        std::cerr <<  ex.what() << '\n';
    }
    catch(Bureaucrat::GradeTooLowException ex)
    {
        std::cerr <<  ex.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Exeption: other exeption called" << std::endl;
    }
    return (0);
}