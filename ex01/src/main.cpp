/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/22 21:32:38 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"

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
        obj2.signForm();
        while (obj1.getGrade() > 1)
            obj1.incrGrade();
        obj1.signForm();
        while (obj1.getGrade() <= 151)
            obj1.decrGrade();
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

