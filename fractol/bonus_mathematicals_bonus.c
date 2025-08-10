/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mathematicals_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:03:19 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 01:03:35 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

double	scale(double unscaled, double old_max, double new_min, double new_max)
{
	double	scaled;

	scaled = (new_max - new_min) * (unscaled - OLD_MIN)
		/ (old_max - OLD_MIN) + new_min;
	return (scaled);
}

t_complex	sum_complex(t_complex c, t_complex z)
{
	t_complex	result;

	result.x = c.x + z.x;
	result.yi = c.yi + z.yi;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.yi * z.yi);
	result.yi = 2 * z.x * z.yi;
	return (result);
}

double	squared_hypotenuse(t_complex z)
{
	double	result;

	result = (z.x * z.x) + (z.yi * z.yi);
	return (result);
}
