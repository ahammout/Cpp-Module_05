/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/24 02:38:05 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"

///-- 1 - Setting up a good main [GOOOOD]
///-- 2 - Check if the a form can be signed by a buraucrat [ Exceptions checking ] [+GOOOD]
///-- 3 - Check all exception cases [ ].
///-- 4 - Overloading operator cat't init all attr [*]
///-- 5 - Check the perfect place to catch the exception to ignore the abord of the program
///-- 6 - Set up the the base then pass to next exe...

int main (void)
{
    //------------------------------- CREATING A FORM -------------------------------------/
    Form form("Chahadat Sokna", false, 1, 4);

    try
    {
        Bureaucrat Br(1550, "Si blhich");
        Br.signForm(form);
        while (Br.getGrade() > 1)
            Br.incrGrade();
        Br.signForm(form);
    }
    catch(Bureaucrat::GradeTooHighException ex)
    {
        std::cerr <<  ex.what() << '\n';
    }
    catch (Form::GradeTooLowException ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Exception: Unexpected exception" << std::endl;
    }
    
    // obj2.signForm(form);
    // while (obj1.getGrade() > 1)
    //     obj1.incrGrade();
    // obj1.signForm(form);

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

