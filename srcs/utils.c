/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:42:09 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 12:57:09 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	get_complex(t_frame frame, uint16_t x, uint16_t y)
{
	t_complex	z;
	double		range;

	range = frame.r_max - frame.r_min;
	z.r = x * (range / frame.w) + frame.r_min;
	range = frame.i_max - frame.i_min;
	z.i = y * (range / frame.h) + frame.i_min;
	return (z);
}

t_complex	make_complex(double r, double i)
{
	t_complex	z;

	z.r = r;
	z.i = i;
	return (z);
}

static t_pixel	interpolate_color(double t, t_pixel min, t_pixel max)
{
	t_pixel		p;

	p.r = floor(min.r + (max.r - min.r) * t);
	p.g = floor(min.g + (max.g - min.g) * t);
	p.b = floor(min.b + (max.b - min.b) * t);
	p.a = floor(min.a + (max.a - min.a) * t);
	return (p);
}

void	compute_gradient(t_gradient *g)
{
	int		i;
	double	f;
	int		j;

	i = 0;
	while (i < g->size)
	{
		f = (double)i / g->size;
		j = 0;
		while (j < g->pts)
		{
			if (f < g->points[j])
			{
				g->comp[i] = interpolate_color(f, g->colors[j - 1],
						g->colors[j]);
				break ;
			}
			j++;
			if (j == g->pts)
				g->comp[i] = rgb(0, 0, 0);
		}
		i++;
	}
}

void	usage(void)
{
	printf("Usage: ./fractol set max_it [c]\n");
	printf("\ttype: julia, mandelbrot or burning_ship\n");
	printf("\tmax_it: an integer\n");
	printf("\tc (only if set == julia):"
		" complex number in the form 'x + yi'.\n");
	printf("\tExample: ./fractol julia '0.1221 + 0.212i'\n");
}
