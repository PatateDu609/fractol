/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:42:18 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 03:31:08 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	quit(void *d)
{
	free_data((t_data *)d);
	exit(0);
}

static void	scroll(t_data *data, double coeff, int x, int y)
{
	t_complex	old_m;
	double		old_range;
	double		range;
	double		ratio_r;
	double		ratio_i;

	old_m = get_complex(data->frame, x, y);
	old_range = data->frame.r_max - data->frame.r_min;
	range = old_range * coeff;
	ratio_r = (old_m.r - data->frame.r_min) / old_range;
	ratio_i = (old_m.i - data->frame.i_min) / old_range;
	data->frame.r_min = old_m.r - range * ratio_r;
	data->frame.i_min = old_m.i - range * ratio_i;
	data->frame.r_max = data->frame.r_min + range;
	data->frame.i_max = data->frame.i_min + range;
	data->zoom *= coeff;
}

int	mouse(int button, int x, int y, void *d)
{
	t_data	*data;
	double	coeff;

	data = (t_data *)d;
	if (button == SCROLL_DOWN)
		coeff = 1. / ZOOM_FACTOR;
	else if (button == SCROLL_UP)
		coeff = ZOOM_FACTOR;
	else
		return (0);
	scroll(data, coeff, x, y);
	fractol(data);
	return (0);
}

static void	arrows(t_data *data, int dx, int dy)
{
	double	d;

	if (dx)
	{
		d = dx * MOVE_INC * data->zoom;
		data->frame.r_min += d;
		data->frame.r_max += d;
	}
	if (dy)
	{
		d = dy * MOVE_INC * data->zoom;
		data->frame.i_min += d;
		data->frame.i_max += d;
	}
	fractol(data);
}

int	key_press(int kc, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (kc == X)
	{
		init_frame(&data->frame);
		fractol(data);
	}
	else if (kc == UP)
		arrows(data, 0, -1);
	else if (kc == DOWN)
		arrows(data, 0, 1);
	else if (kc == LEFT)
		arrows(data, -1, 0);
	else if (kc == RIGHT)
		arrows(data, 1, 0);
	else if (kc == ESC)
		mlx_loop_end(data->mlx);
	return (1);
}
