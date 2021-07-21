/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:42:18 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/21 19:38:10 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	quit(void *d)
{
	free_data((t_data *)d);
	exit(0);
}

static void	scroll(t_data *data, FLOAT coeff, int x, int y)
{
	t_complex	m;
	t_complex	old_m;
	int			out;

	old_m = get_complex(data->frame, x, y);
	m = old_m;
	m.r *= coeff;
	m.i *= coeff;
	out = (coeff > 1);
	data->frame.r_min = (data->frame.r_min + old_m.r) * coeff - old_m.r * out;
	data->frame.i_min = (data->frame.i_min + old_m.i) * coeff - old_m.i * out;
	data->frame.r_max = (data->frame.r_max + old_m.r) * coeff - old_m.r * out;
	data->frame.i_max = (data->frame.i_max + old_m.i) * coeff - old_m.i * out;
	printf("frame (coeff = %.3lf): min = %.3lf + %.3lfi, max = %.3lf + %.3lfi\n",
		coeff,
		data->frame.r_min, data->frame.i_min,
		data->frame.r_max, data->frame.i_max);
	data->zoom *= coeff;
}

int	mouse(int button, int x, int y, void *d)
{
	t_data	*data;
	FLOAT	coeff;

	data = (t_data *)d;
	if (button == SCROLL_DOWN)
		coeff = (FLOAT)1 / ZOOM_FACTOR;
	else if (button == SCROLL_UP)
		coeff = ZOOM_FACTOR;
	else
		return (0);
	scroll(data, coeff, x, y);
	fractol(data);
	return (0);
}

static void		arrows(t_data *data, int dx, int dy)
{
	FLOAT	d;

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
