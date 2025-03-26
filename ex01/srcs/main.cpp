/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urabex <urabex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:59:35 by urabex            #+#    #+#             */
/*   Updated: 2025/03/26 15:17:19 by urabex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main(void) {
    int i_array[] = {1, 2, 3, 4, 5};
    std::cout << "arr1: " << std::flush;
	iter(i_array, 5, &out);
	std::cout << std::endl;

    std::string	s_array[] = { "hel", "lo", "Wor", "ld", "!" };
	std::cout << "arr2: " << std::flush;
	iter(s_array, 5, &out);
	std::cout << std::endl;

	float f_array[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::cout << "arr3: " << std::flush;
	iter(f_array, 5, &out);
	std::cout << std::endl;
}
