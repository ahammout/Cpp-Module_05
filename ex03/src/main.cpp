/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:19:26 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 16:35:55 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

// void    f(){
//     system("leaks Bureaucrat");
// }

int main(void)
{
    // atexit(f);
    Intern  someRandomIntern;
    Bureaucrat  Br(1, "Mark");
    AForm   *rrf;

    try
    {
        rrf = someRandomIntern.makeForm(" request", "Robo");
        Br.signForm(*rrf);
        Br.executeForm(*rrf);
        delete rrf; 
    }
    catch (Intern::FormNotExist &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "╳: Enexpected error" << std::endl;
    }
    // Br.signForm(rrf);
    return (0);
}