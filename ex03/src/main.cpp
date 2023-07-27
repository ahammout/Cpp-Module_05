/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:19:26 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 21:45:51 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
    Intern  someRandomIntern;
    AForm   *rrf;

    try
    {
        rrf = someRandomIntern.makeForm("shrubbery request", "Office");
        try
        {
            Bureaucrat  Br(1, "Mark");
            Br.signForm(*rrf);
            Br.executeForm(*rrf);
            delete rrf;
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
    }
    catch (Intern::FormNotExist &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "╳: Enexpected error" << std::endl;
    }
    return (0);
}