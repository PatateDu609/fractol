/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 03:03:33 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/21 02:03:29 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void init_mlx(t_data *data)
{
	int tmp;

	data->mlx = chk_non_null(mlx_init(), MLX_INIT_FAILED);
	data->win = chk_non_null(mlx_new_window(data->mlx, data->frame.w,
		data->frame.h, NAME), MLX_WIN_FAILED);
	data->mlx_img = chk_non_null(mlx_new_image(data->mlx, data->frame.w,
		data->frame.h), MLX_IMG_FAILED);
	data->image = (t_pixel *)mlx_get_data_addr(data->mlx_img, &tmp, &tmp, &tmp);
}

static void init_hook(t_data *data)
{
	mlx_hook(data->win, 33, 1L << 17, quit, data);
	mlx_hook(data->win, 4, 1L << 2, mouse, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx, fractol_hook, data);
}

static void init_frame(t_frame *frame)
{
	frame->r_min = -2;
	frame->i_min = -2;
	frame->r_max = 2;
	frame->i_max = 2;
}

static void init_gradient(t_gradient *g)
{
	g->size = 2048;
	g->pts = 5;

	g->points = chk_non_null(malloc(sizeof(FLOAT) * g->pts), MALLOC_FAILED);
	g->colors = chk_non_null(malloc(sizeof(t_pixel) * g->pts), MALLOC_FAILED);
	g->comp = chk_non_null(malloc(sizeof(t_pixel) * g->size), MALLOC_FAILED);

	g->points[0] = 0.0;
	g->colors[0] = rgb(0, 7, 100);
	g->points[1] = 0.16;
	g->colors[1] = rgb(32, 107, 203);
	g->points[2] = 0.42;
	g->colors[2] = rgb(237, 255, 255);
	g->points[3] = 0.6425;
	g->colors[3] = rgb(255, 170, 0);
	g->points[4] = 0.8575;
	g->colors[4] = rgb(0, 2, 0);

	compute_gradient(g);
}

t_data		*init(int w, int h)
{
	t_data	*data;

	data = chk_non_null(malloc(sizeof(t_data)), MALLOC_FAILED);
	data->frame.w = w;
	data->frame.h = h;
	data->zoom = 1;
	init_mlx(data);
	init_hook(data);
	init_frame(&data->frame);
	init_gradient(&data->g);
	return (data);
}
