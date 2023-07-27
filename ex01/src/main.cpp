/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 19:00:57 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"

int main (void)
{
    //------------------------------- FORM CREATION -------------------------------------/
    Form form("Registration Form", false, 1, 4);

    try
    {
        Bureaucrat Br(45, "Mark");
        Br.signForm(form);
        while (Br.getGrade() > 1)
            Br.incrGrade();
        Br.signForm(form);
    }
    catch(Bureaucrat::GradeTooHighException ex)
    {
        std::cerr <<  ex.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "╳: " << "Unexpected error" << std::endl;
    }
    return (0);
}

