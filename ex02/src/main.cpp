/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:19:26 by ahammout          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:22 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
    ///@note Test the abstract class ShrubberyCreationForm.
    AForm   *form;
    
    form = ShrubberyCreationForm;
    std::cout << "The name of the form: "<< form->getName() << std::endl;
    return (0);
}