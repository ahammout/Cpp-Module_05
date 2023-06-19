/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:37:29 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/19 15:43:17 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.cpp"

int main (void)
{
    Bureaucrat obj;
    
    // std::cout <<  obj.getGrade() << std::endl;
    try
    {
        obj.incrGrade();
    }
    /// @param const std::exception& e
    catch(int i)
    {
        std::cerr << "Exeption: N' " << i << '\n';
    }
    catch (...)
    {
        std::cerr << "Def exeption called" << std::endl;
    }
    
    // std::cout <<  obj.getGrade() << std::endl;    

    return (0);
}