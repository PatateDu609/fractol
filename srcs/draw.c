/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 02:32:43 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 03:33:37 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel	rgb(uint8_t r, uint8_t g, uint8_t b)
{
	t_pixel		p;

	p.r = r;
	p.g = g;
	p.b = b;
	p.a = 0;
	return (p);
}

void	push_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->mlx_img, 0, 0);
}
