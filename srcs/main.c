/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:03:44 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/21 01:56:12 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"

#include "fractol.h"

int		fractol_hook(void *d)
{
	(void)d;
	return (0);
}

int		main()
{
	int	w, h;
	w = 500;
	h = 500;

	t_data *data = init(w, h);
	data->max_it = 100;

	fractol(data);
	mlx_loop(data->mlx);
	free_data(data);
	return (0);
}
