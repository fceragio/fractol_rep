/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_strings_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:07:06 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 01:07:49 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

int	put_char(char c)
{
	return (write(1, &c, 1));
}

void	put_string(char *str)
{
	if (str)
	{
		while (*str)
		{
			put_char(*str);
			str++;
		}
	}
}

int	strings_are_equal(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (FAILURE);
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (SUCCESS);
	else
		return (FAILURE);
}
