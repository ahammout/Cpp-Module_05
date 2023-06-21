/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/21 14:42:40 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

int main (void)
{
    Bureaucrat obj;
    
    // std::cout <<  obj.getGrade() << std::endl;
    ///@note This main is like shit, add more tests and do your fucking job
    try
    {
        std::cout <<  obj << std::endl;
        /// test with copy constrctor copy assignment operator
        // obj = Bureaucrat(190);
        obj.decrGrade();
    }
    ///@param const std::exception& ex
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
        std::cerr << "Exeption: unexpected exception" << std::endl;
    }
    return (0);
}