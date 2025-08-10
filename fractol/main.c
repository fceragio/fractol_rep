/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:55:51 by federico          #+#    #+#             */
/*   Updated: 2024/09/19 23:57:28 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && strings_are_equal(argv[1], "Mandelbrot"))
		mandelbrot(argv[1]);
	else if (argc == 4 && strings_are_equal(argv[1], "Julia")
		&& (real_number(argv[2]) && real_number(argv[3])))
		julia(argv[1], convert_string_to_double(argv[2]),
			convert_string_to_double(argv[3]));
	else
		explain_fractol();
	return (0);
}
