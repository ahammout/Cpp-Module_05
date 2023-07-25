/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/25 22:20:28 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"

///@note Change the error messages and exception warnings.
///@note clean the code and the main.

int main (void)
{
    //------------------------------- CREATING A FORM -------------------------------------/
    Form form("Chahadat Sokna", false, 1, 4);

    try
    {
        Bureaucrat Br(45, "Si blhich");
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
    
    //------------------------------ NO EXCEPTION CATCHED ------------------------------//

    // try
    // {
    //     Bureaucrat Br(150, "Si blhich");
    //     while (Br.getGrade() > 1)
    //         Br.incrGrade();
    //     Br.signForm(form);
    // }
    // catch(Bureaucrat::GradeTooHighException ex)
    // {
    //     std::cerr <<  ex.what() << '\n';
    // }
    // catch(Bureaucrat::GradeTooLowException ex)
    // {
    //     std::cerr <<  ex.what() << '\n';
    // }
    // catch (...)
    // {
    //     std::cerr << "╳: " << Unexpected error" << std::endl;
    // }

    return (0);
}

