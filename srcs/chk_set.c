/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 06:05:17 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 06:24:02 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	chk_julia(t_data *data, int ac, char **av)
{
	if (ft_strcmp(ft_tolower(av[1]), "julia") || ac != 4)
		return (0);
	if (!ft_iscomplex(av[3]))
		return (0);
	data->set = JULIA;
	data->julia_c = parse_complex(av[3]);
	return (1);
}

int	chk_burning_sheep(t_data *data, int ac, char **av)
{
	if (ft_strcmp(ft_tolower(av[1]), "burning_sheep") || ac != 3)
		return (0);
	data->set = BURNING_SHIP;
	return (1);
}

int	chk_mandelbrot(t_data *data, int ac, char **av)
{
	if (ft_strcmp(ft_tolower(av[1]), "mandelbrot") || ac != 3)
		return (0);
	data->set = MANDELBROT;
	return (1);
}
