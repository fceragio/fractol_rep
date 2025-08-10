/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:36 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 00:36:18 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && strings_are_equal(argv[1], "Mandelbrot"))
		mandelbrot(argv[1]);
	else if (argc == 2 && strings_are_equal(argv[1], "BurningShip"))
		burning_ship(argv[1]);
	else if (argc == 4 && strings_are_equal(argv[1], "Julia")
		&& (real_number(argv[2]) && real_number(argv[3])))
		julia(argv[1], convert_string_to_double(argv[2]),
			convert_string_to_double(argv[3]));
	else
		explain_fractol();
	return (0);
}
