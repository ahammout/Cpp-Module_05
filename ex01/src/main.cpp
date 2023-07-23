/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/23 21:39:26 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"

///@brief Refactor the main tests:
/*
    ***!TEST-1-: The first test is about creating a simple form object
    ***+ Handle form exceptions, Handling form exceptions in the main,
    + Creating a Bureaucrat object, the class of this object has a method, named sign form
    That method checks if the form it's signed or not, if it's signed then it will print an appropriate
    message, if not it will throw an exception, Now the exception is throwen inside the method and not in the main,
    the main it stell waiting for catching an exception,
*/

int main (void)
{
    //------------------------------- FORM TESTS ---------------/
    Form form("Chahadat l7ayat", false, 1, 4);
    std::cout << "Form Attributes: \n" << form;
    std::cout << "---------------------------------------------------------" << std::endl;

    //---------------------------- THROWING EXCEPTION CASES-----------------------------//
    Bureaucrat obj1(145, "Si blhich");
    Bureaucrat obj2(obj1);

    try
    {
        form.beSigned(obj1);
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
    // Bureaucrat obj1(15, "Si blhich");
    // Bureaucrat obj2(obj1);

    // try
    // {
        
    //     while (obj1.getGrade() > 1)
    //         obj1.incrGrade();
    //     obj2 = obj1;
    //     obj1.signForm();
    //     obj2.signForm();
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

