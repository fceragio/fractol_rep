/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rendering_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 02:35:12 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 00:36:45 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

void	put_pixel(t_mlx_data *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->line_len) + (x * (data->bpp / 8));
	*(unsigned int *)(data->bit_address + offset) = color;
}

void	render_mandelbrot(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_by_pixel_mandelbrot(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->instance,
		data->window, data->image, MLX_DEFAULT, MLX_DEFAULT);
}

void	pixel_by_pixel_mandelbrot(int x, int y, t_mlx_data *data)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	z.x = 0.0;
	z.yi = 0.0;
	c.x = (scale((double)x, WIDTH, -2, 2)
			* data->parameters.zoom_state) + data->parameters.shift_x;
	c.yi = (scale((double)y, HEIGHT, 2, -2)
			* data->parameters.zoom_state) + data->parameters.shift_y;
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

void	render_fractal(t_mlx_data *data)
{
	if (strings_are_equal(data->parameters.name, "Mandelbrot"))
		render_mandelbrot(data);
	if (strings_are_equal(data->parameters.name, "Julia"))
		render_julia(data);
	if (strings_are_equal(data->parameters.name, "BurningShip"))
		render_ship(data);
}
