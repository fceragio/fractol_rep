/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mandelbrot_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:06:17 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 01:06:50 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

void	mandelbrot(char	*name)
{
	t_mlx_data	data;

	initialize_mlx(&data, name);
	initialize_parameters_mandelbrot(&data, name);
	render_mandelbrot(&data);
	hook_handlers(&data);
	mlx_loop(data.instance);
}

static void	close_mlx(t_mlx_data *data)
{
	mlx_destroy_image(data->instance, data->image);
	mlx_destroy_window(data->instance, data->window);
	mlx_destroy_display(data->instance);
	free(data->instance);
}

void	initialize_mlx(t_mlx_data *data, char *name)
{
	data->instance = mlx_init();
	if (!data->instance)
		malloc_error('A');
	data->window = mlx_new_window(data->instance, WIDTH, HEIGHT, name);
	if (!data->window)
	{
		mlx_destroy_display(data->instance);
		free(data->instance);
		malloc_error('B');
	}
	data->image = mlx_new_image(data->instance, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_destroy_window(data->instance, data->window);
		mlx_destroy_display(data->instance);
		free(data->instance);
		malloc_error('C');
	}
	data->bit_address = mlx_get_data_addr(data->image, &data->bpp,
			&data->line_len, &data->endian);
	if (!data->bit_address)
	{
		close_mlx(data);
		malloc_error('D');
	}
}

int	close_everything(t_mlx_data *data)
{
	mlx_destroy_image(data->instance, data->image);
	mlx_destroy_window(data->instance, data->window);
	mlx_destroy_display(data->instance);
	free(data->instance);
	exit(SUCCESS);
}

void	initialize_parameters_mandelbrot(t_mlx_data *data, char *name)
{
	data->parameters.name = name;
	data->parameters.zoom_state = 1.0;
	data->parameters.shift_x = 0.0;
	data->parameters.shift_y = 0.0;
	data->parameters.fractal_iterations = FRACTAL_ITERATIONS;
}
