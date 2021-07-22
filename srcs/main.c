/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:03:44 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 14:04:43 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"

#include "fractol.h"

int	fractol_hook(void *d)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *)d;
	if (data->autozoom)
	{
		mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
		if (data->shift)
			scroll(data, ZOOM_FACTOR, x, y);
		else
			scroll(data, 1. / ZOOM_FACTOR, x, y);
		fractol(data);
	}
	else if (data->dx || data->dy)
		arrows(data, data->dx, data->dy);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		w;
	int		h;

	w = 750;
	h = 750;
	data = init(ac, av, w, h);
	fractol(data);
	mlx_loop(data->mlx);
	free_data(data);
	return (0);
}
