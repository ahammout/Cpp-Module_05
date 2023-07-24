/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/24 20:04:04 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"

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
        std::cout << "Exception: Unexpected exception" << std::endl;
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
    //     std::cerr << "Exeption: unexpected exception" << std::endl;
    // }

    return (0);
}

