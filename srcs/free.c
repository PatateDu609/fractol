/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:54:18 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 03:27:00 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	destroy_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

static void	free_gradient(t_gradient g)
{
	free(g.points);
	free(g.comp);
	free(g.colors);
}

void	free_data(t_data *data)
{
	destroy_mlx(data);
	free_gradient(data->g);
	free(data);
}
