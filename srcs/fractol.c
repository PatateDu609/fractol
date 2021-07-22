/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:52:14 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 06:16:38 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	mandelbrot(t_complex c, t_complex z, int burning)
{
	t_complex	z1;
	double		temp;

	temp = z.r * z.r - z.i * z.i + c.r;
	if (!burning)
		z1.i = 2.0 * z.r * z.i + c.i;
	else
		z1.i = fabs(2.0 * z.r * z.i) + c.i;
	z1.r = temp;
	return (z1);
}

static int	compute_set(t_complex c, int max_it, t_complex *z, int burning)
{
	int		i;

	i = 0;
	while (i < max_it && z->r * z->r + z->i * z->i < 4)
	{
		*z = mandelbrot(c, *z, burning);
		i++;
	}
	return (i);
}

static int	chk_set(t_data *data, t_complex *z, int x, int y)
{
	t_complex	c;

	if (data->set == MANDELBROT || data->set == BURNING_SHIP)
	{
		c = get_complex(data->frame, x, y);
		*z = make_complex(0, 0);
	}
	else if (data->set == JULIA)
	{
		c = data->julia_c;
		*z = get_complex(data->frame, x, y);
	}
	return (compute_set(c, data->max_it, z, data->set == BURNING_SHIP));
}

static t_pixel	compute_color(t_gradient g, t_complex z, int max_it)
{
	double	smoothed;
	double	magn;
	int		lerped_i;

	magn = z.r * z.r + z.i * z.i;
	smoothed = log2(log2(sqrt(magn)) / 2);
	lerped_i = (int)(sqrt(max_it + 10 - smoothed) * 256) % g.size;
	return (g.comp[lerped_i]);
}

void	fractol(t_data *data)
{
	int			x;
	int			y;
	int			n;
	t_complex	z;

	y = 0;
	while (y < data->frame.h)
	{
		x = 0;
		while (x < data->frame.w)
		{
			n = chk_set(data, &z, x, y);
			data->image[y * data->frame.w + x] = compute_color(data->g, z, n);
			x++;
		}
		y++;
	}
	push_image(data);
}
