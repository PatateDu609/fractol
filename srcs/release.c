/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:31:47 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 14:26:12 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_release(int kc, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	data->max_it *= 2;
	if (kc == F)
		data->autozoom = 0;
	else if (kc == SHIFT)
		data->shift = 0;
	else if (kc == UP || kc == DOWN)
		data->dy = 0;
	else if (kc == LEFT || kc == RIGHT)
		data->dx = 0;
	fractol(data);
	return (1);
}
