/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:02:58 by federico          #+#    #+#             */
/*   Updated: 2024/09/20 00:28:17 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	else
		return (FAILURE);
	render_fractal(data);
	return (SUCCESS);
}

int	mouse_handling(int button, int x, int y, t_mlx_data *data)
{
	if (button == 4 && x <= WIDTH && y <= HEIGHT)
		data->parameters.zoom_state *= 0.95;
	else if (button == 5 && x <= WIDTH && y <= HEIGHT)
		data->parameters.zoom_state *= 1.05;
	else
		return (FAILURE);
	render_fractal(data);
	return (SUCCESS);
}
