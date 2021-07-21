/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:42:09 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/21 04:04:04 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	get_complex(t_frame frame, uint16_t x, uint16_t y)
{
	t_complex	z;
	FLOAT		range;

	range = frame.r_max - frame.r_min;
	z.r = x * (range / frame.w) + frame.r_min;
	range = frame.i_max - frame.i_min;
	z.i = y * (range / frame.h) + frame.i_min;
	return (z);
}

// static FLOAT cubic_interpolation(FLOAT p[4], FLOAT x)
// {
// 	return (p[1] +
// 			0.5 * x * (p[2] - p[0] +
// 			x * (2.0 * p[0] - 5.0 * p[1] + 4.0 * p[2] - p[3] +
// 			x * (3.0 * (p[1] - p[2]) + p[3] - p[0]))));
// }

static t_pixel	interpolate_color(FLOAT t, t_pixel min, t_pixel max)
{
	t_pixel		p;

	p.r = FLOOR(min.r + (max.r - min.r) * t);
	p.g = FLOOR(min.g + (max.g - min.g) * t);
	p.b = FLOOR(min.b + (max.b - min.b) * t);
	p.a = FLOOR(min.a + (max.a - min.a) * t);
	return p;
}

void			compute_gradient(t_gradient *g)
{
	int		i;
	FLOAT	f;
	int		j;

	i = 0;
	while (i < g->size)
	{
		f = (FLOAT)i / g->size;
		j = 0;
		while (j < g->pts)
		{
			if (f < g->points[j])
			{
				g->comp[i] = interpolate_color(f, g->colors[j - 1],
					g->colors[j]);
				break;
			}
			j++;
			if (j == g->pts)
				g->comp[i] = rgb(0, 0, 0);
		}
		i++;
	}
}
