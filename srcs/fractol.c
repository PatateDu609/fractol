/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:52:14 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/21 01:42:09 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		chk_set(t_complex c, int max_it, t_complex *z)
{
	int			i = 0;

	z->i = 0;
	z->r = 0;
	while (i < max_it && z->r * z->r + z->i * z->i < 4)
	{
		FLOAT temp = z->r * z->r - z->i * z->i + c.r;
		z->i = 2.0 * z->r * z->i + c.i;
		z->r = temp;
		i++;
	}
	return (i);
}

void fractol(t_data *data)
{
	for (int y = 0; y < data->frame.h; y++)
	{
		for (int x = 0; x < data->frame.w; x++)
		{
			t_complex c = get_complex(data->frame, x, y);
			t_complex z;
			int n = chk_set(c, data->max_it, &z);

			FLOAT smoothed;
			FLOAT magn;
			magn = z.r * z.r + z.i * z.i;
			smoothed = LOG2(LOG2(SQRT(magn)) / 2);
			int lerped_i;

			lerped_i = (int)(SQRT(n + 10 - smoothed) * 256) % data->g.size;
			data->image[y * data->frame.w + x] = data->g.comp[lerped_i];
		}
	}
	push_image(data);
}
