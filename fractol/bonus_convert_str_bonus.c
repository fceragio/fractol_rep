/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_convert_str_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:04:38 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 01:45:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

static double	decimal_part(char *str)
{
	double	result;
	double	pow;

	pow = 1;
	result = 0;
	if (!str || !*str)
		return (0);
	while (*str)
	{
		pow = pow / 10;
		result = result + ((*str - '0') * pow);
		str++;
	}
	return (result);
}

double	convert_string_to_double(char *str)
{
	double	sign;
	double	result;

	result = 0;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str && *str == '.')
		str++;
	return ((result + decimal_part(str)) * sign);
}

int	real_number(char *str)
{
	if (!str || !*str)
		return (FAILURE);
	if (*str == '+' || *str == '-' || (*str >= '0' && *str <= '9'))
		str++;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (!*str)
		return (SUCCESS);
	if (*str != '.')
		return (FAILURE);
	str++;
	if (!*str)
		return (FAILURE);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (!*str)
		return (SUCCESS);
	else
		return (FAILURE);
}
