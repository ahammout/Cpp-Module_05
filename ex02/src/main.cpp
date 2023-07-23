/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:19:26 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/23 17:02:13 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

///@note Refactor the method signForm in beraucrat class

int main(void)
{
    ///@note Test the abstract class ShrubberyCreationForm.
    Bureaucrat  Br(150, "Mark");
    ShrubberyCreationForm   shForm("Home");
    try
    {
        Br.signForm(shForm);
    }
    catch(Bureaucrat::GradeTooHighException ex)
    {
        std::cerr <<  ex.what() << '\n';
    }
    catch(Bureaucrat::GradeTooLowException ex)
    {
        std::cerr <<  ex.what() << '\n';
    }
    catch(AForm::GradeTooHighException ex)
    {
        std::cerr <<  ex.what() << '\n';
    }
    catch(AForm::GradeTooLowException ex)
    {
        std::cerr <<  ex.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Exeption: unexpected exception" << std::endl;
    } 
   //-------------- TESTs TO CHECK THE ShrubberyCreationForm Derived class ------------------/
    ///@note Display attributes
    // std::cout << "The name of the form: "<< shForm.getName() << std::endl;
    // std::cout << "Signature status: " << shForm.getSignature() << std::endl;
    // std::cout << "Required grade to sign: " << shForm.getSgrade() << std::endl;
    // std::cout << "Required   to execute: " << shForm.getExGrade() << std::endl;
    // std::cout << "The target: " << shForm.getTarget() << std::endl;

    // ///@note Check The overloaded operators and other Constuctors and methods
    // std::cout << "----------------------- Copy Constructor -------------------------\n" << std::endl;
    // ShrubberyCreationForm   shFormTmp(shForm);

    // std::cout << "The name of the form: "<< shForm.getName() << std::endl;
    // std::cout << "Signature status: " << shForm.getSignature() << std::endl;
    // std::cout << "Required grade to sign: " << shForm.getSgrade() << std::endl;
    // std::cout << "Required grade to execute: " << shForm.getExGrade() << std::endl;
    // std::cout << "The target: " << shForm.getTarget() << std::endl;
    
    // std::cout << "----------------------- Overloading OPs ' = <<'-------------------------\n" << std::endl;
    // ShrubberyCreationForm   shForm3;

    // shForm3 = shForm;
    // // std::cout << "The name of the form: "<< shForm3.getName() << std::endl;
    // // std::cout << "Signature status: " << shForm3.getSignature() << std::endl;
    // // std::cout << "Required grade to sign: " << shForm3.getSgrade() << std::endl;
    // // std::cout << "Required grade to execute: " << shForm3.getExGrade() << std::endl;
    // // std::cout << "The target: " << shForm3.getTarget() << std::endl;
    // std::cout << shForm3 << std::endl;
    
    return (0);
}