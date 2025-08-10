/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_events_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 02:13:48 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 00:35:42 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_fractol_bonus.h"

void	hook_handlers(t_mlx_data *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask, key_press_handling, data);
	mlx_hook(data->window, ButtonPress, ButtonPressMask, mouse_handling, data);
	mlx_hook(data->window, DestroyNotify,
		StructureNotifyMask, close_everything, data);
	mlx_hook(data->window, VisibilityNotify,
		VisibilityChangeMask, visibility_handling, data);
}

int	visibility_handling(t_mlx_data *data)
{
	render_fractal(data);
	return (SUCCESS);
}

int	key_press_handling(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		close_everything(data);
	else if (strings_are_equal(data->parameters.name, "BurningShip"))
		key_press_ship(keysym, data);
	else if (keysym == XK_Left)
		data->parameters.shift_x += 0.2 * data->parameters.zoom_state;
	else if (keysym == XK_Right)
		data->parameters.shift_x -= 0.2 * data->parameters.zoom_state;
	else if (keysym == XK_Up)
		data->parameters.shift_y -= 0.2 * data->parameters.zoom_state;
	else if (keysym == XK_Down)
		data->parameters.shift_y += 0.2 * data->parameters.zoom_state;
	else if (keysym == XK_space && data->parameters.fractal_iterations < 1024)
		data->parameters.fractal_iterations += 1;
	else if (keysym == XK_minus && data->parameters.fractal_iterations > 8)
		data->parameters.fractal_iterations -= 1;
	else
		return (FAILURE);
	render_fractal(data);
	return (SUCCESS);
}

int	mouse_handling(int button, int x, int y, t_mlx_data *data)
{
	if (button == 4)
		data->parameters.zoom_state *= 0.95;
	else if (button == 5)
		data->parameters.zoom_state *= 1.05;
	else if (button == 1 && strings_are_equal(data->parameters.name, "Julia"))
	{
		data->parameters.julia_x = (scale((double)x, WIDTH, -2, 2)
				* data->parameters.zoom_state) + data->parameters.shift_x;
		data->parameters.julia_y = (scale((double)y, HEIGHT, -2, 2)
				* data->parameters.zoom_state) + data->parameters.shift_y;
	}
	else
		return (FAILURE);
	render_fractal(data);
	return (SUCCESS);
}

int	key_press_ship(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Left)
		data->parameters.shift_x += 0.2 * data->parameters.zoom_state;
	else if (keysym == XK_Right)
		data->parameters.shift_x -= 0.2 * data->parameters.zoom_state;
	else if (keysym == XK_Up)
		data->parameters.shift_y += 0.2 * data->parameters.zoom_state;
	else if (keysym == XK_Down)
		data->parameters.shift_y -= 0.2 * data->parameters.zoom_state;
	else if (keysym == XK_space && data->parameters.fractal_iterations < 1024)
		data->parameters.fractal_iterations += 1;
	else if (keysym == XK_minus && data->parameters.fractal_iterations > 8)
		data->parameters.fractal_iterations -= 1;
	else
		return (FAILURE);
	return (SUCCESS);
}
