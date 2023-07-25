/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:19:26 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/25 21:15:46 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

///@note Refactor the method signForm in beraucrat class
///@note Make all the messages that are printed in the stdout combined with some unicode character to make it clear!
///@note need to do deep test to test the constructors and overloading operators.

int main(void)
{
    ///@note Test the abstract class ShrubberyCreationForm.
    Bureaucrat  Br(150, "Mark");
    Bureaucrat  Br1(40, "Elon");
    Bureaucrat  Br2(15, "Trump");
    ShrubberyCreationForm   shForm("Zitone");
    RobotomyRequestForm     RobForm("Robo");
    PresidentialPardonForm  PreForm("Prisoner");
 
    try
    {
        Br.signForm(&shForm);
        while (Br.getGrade() > 130)
            Br.incrGrade();
        //--- SIGN FORMS -----/
        Br.signForm(&shForm);
        Br1.signForm(&RobForm);
        Br2.signForm(&PreForm);
        
        //--- EXEC FORMS -----/
        Br.executeForm(shForm);
        Br1.executeForm(RobForm);
        Br2.executeForm(PreForm);
        
        
    }
    catch(const Bureaucrat::GradeTooHighException &ex)
    {
        std::cerr <<  ex.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException &ex)
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

    ///@note Check The overloaded operators and other Constuctors and methods
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