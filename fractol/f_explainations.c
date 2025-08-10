/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_explainations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:59:02 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 00:23:22 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	explain_mandelbrot(void)
{
	put_string("MANDELBROT SET\n./fractol Mandelbrot\n\n");
}

static void	explain_julia(void)
{
	put_string("JULIA SET\n./fractol Julia \"double x\" \"double y\"\n");
	put_string("With double_x and double_y we mean real_numbers.\n");
	put_string("Please notice that only one sign character + or -,\n");
	put_string("and, beside the dot \'.\' \"only one\",\n");
	put_string("no non-digit character will be allowed\n");
	put_string("EXAMPLES:\n\t+0\n\t-9\n\t1.3\n\t+6.0\n\t0.0310\n\t-12.01\n");
	put_string("TIP:\n");
	put_string("The range of values that corrispond to worth viewing images\n");
	put_string("can only be found between -2 and +2\n");
}

void	explain_fractol(void)
{
	put_string("\nPossible executions:\n\n");
	explain_mandelbrot();
	explain_julia();
}

void	malloc_error(char position)
{
	put_string("Malloc failed in position ");
	put_char(position);
	put_char('\n');
	exit(FAILURE);
}
