/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/22 19:57:00 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

int main (void)
{
    Bureaucrat obj1(1, "Si blhich");
    Bureaucrat obj2(obj1);

    try
    {
        std::cout << obj1 << std::endl;
        std::cout << obj2.getGrade() << std::endl;
        while (obj2.getGrade() <= 151)
            obj2.decrGrade();
        std::cout << obj2 << std::endl;
    }
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