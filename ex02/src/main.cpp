/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:19:26 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/24 19:10:56 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

///@note
    

int main(void)
{
    ///@note Test the abstract class ShrubberyCreationForm.
    AForm   form;

    form = AForm("Certificate", false, 3, 1);
    std::cout << "The name of the form: "<< form.getName() << std::endl;
    return (0);
}