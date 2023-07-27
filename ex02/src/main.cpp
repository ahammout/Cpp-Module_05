/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:19:26 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 21:49:21 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat  Br(150, "Mark");
    Bureaucrat  Br1(40, "Elon");
    Bureaucrat  Br2(15, "Trump");
    ShrubberyCreationForm   shForm("Zitone");
    RobotomyRequestForm     RobForm("Robo");
    PresidentialPardonForm  PreForm("Prisoner");
 
    std::cout << Br;
    std::cout << Br1;
    std::cout << Br2;
    std::cout << shForm;
    std::cout << RobForm;
    std::cout << PreForm;

    
    try
    {
        Br.signForm(shForm);
        while (Br.getGrade() > 130)
            Br.incrGrade();
        //--- SIGN FORMS -----/
        Br.signForm(shForm);
        Br1.signForm(RobForm);
        Br2.signForm(PreForm);
        
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
        std::cerr << "╳: unexpected error" << std::endl;
    }
    return (0);
}