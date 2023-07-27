/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/27 18:48:00 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/Bureaucrat.hpp"

int main (void)
{
    Bureaucrat Br(1, "Mark");
    // Bureaucrat Br2(16, "Elon");
    // Bureaucrat Br1(Br);

    // Br1 = Br2;
    // std::cout << Br1 << std::endl;
   
    try
    {
        std::cout << Br << std::endl;
        while (Br.getGrade() < 150)
            Br.decrGrade();
        std::cout << Br << std::endl;
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
        std::cerr << "╳: unexpected error" << std::endl;
    }
    return (0);
}