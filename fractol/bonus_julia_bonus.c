/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_julia_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:05:26 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 01:10:26 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

void	julia(char	*name, double julia_x, double julia_y)
{
	t_mlx_data	data;

	initialize_mlx(&data, name);
	initialize_parameters_julia(&data, name, julia_x, julia_y);
	render_julia(&data);
	hook_handlers(&data);
	mlx_loop(data.instance);
}

void	initialize_parameters_julia(t_mlx_data *data,
		char *name, double julia_x, double julia_y)
{
	data->parameters.name = name;
	data->parameters.zoom_state = 1.0;
	data->parameters.shift_x = 0.0;
	data->parameters.shift_y = 0.0;
	data->parameters.fractal_iterations = FRACTAL_ITERATIONS;
	data->parameters.julia_x = julia_x;
	data->parameters.julia_y = julia_y;
}

void	render_julia(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_by_pixel_julia(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->instance,
		data->window, data->image, MLX_DEFAULT, MLX_DEFAULT);
}

void	pixel_by_pixel_julia(int x, int y, t_mlx_data *data)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	z.x = (scale((double)x, WIDTH, -2, 2)
			* data->parameters.zoom_state) + data->parameters.shift_x;
	z.yi = (scale((double)y, HEIGHT, 2, -2)
			* data->parameters.zoom_state) + data->parameters.shift_y;
	c.x = data->parameters.julia_x;
	c.yi = data->parameters.julia_y;
	i = 0;
	while (i < data->parameters.fractal_iterations)
	{
		z = sum_complex(square_complex(z), c);
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
