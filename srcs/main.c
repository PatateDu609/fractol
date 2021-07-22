/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:03:44 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 06:39:58 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"

#include "fractol.h"

int	fractol_hook(void *d)
{
	(void)d;
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
