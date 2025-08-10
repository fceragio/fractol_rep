/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_burningship_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:28:54 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 00:35:28 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

void	burning_ship(char *name)
{
	t_mlx_data	data;

	initialize_mlx(&data, name);
	initialize_parameters_mandelbrot(&data, name);
	render_ship(&data);
	hook_handlers(&data);
	mlx_loop(data.instance);
}

void	render_ship(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_by_pixel_ship(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->instance,
		data->window, data->image, MLX_DEFAULT, MLX_DEFAULT);
}

t_complex	square_complex_ship(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.yi * z.yi);
	if ((z.x >= 0 && z.yi >= 0) || (z.x <= 0 && z.yi <= 0))
		result.yi = 2 * z.x * z.yi;
	else
		result.yi = -2 * z.x * z.yi;
	return (result);
}

void	pixel_by_pixel_ship(int x, int y, t_mlx_data *data)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	z.x = 0.0;
	z.yi = 0.0;
	c.x = (scale((double)x, WIDTH, -2, 2)
			* data->parameters.zoom_state) + data->parameters.shift_x;
	c.yi = (scale((double)y, HEIGHT, -2, 2)
			* data->parameters.zoom_state) + data->parameters.shift_y;
	i = 0;
	while (i < data->parameters.fractal_iterations)
	{
		z = sum_complex(square_complex_ship(z), c);
		if (squared_hypotenuse(z) > ESCAPE_VALUE)
		{
			color = (scale((double)i,
						data->parameters.fractal_iterations, BLACK, WHITE));
			put_pixel(data, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel(data, x, y, FRACTAL_COLOR);
}
