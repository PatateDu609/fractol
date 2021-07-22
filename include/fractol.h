/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 02:16:35 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 12:57:48 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef NAME
#  undef NAME
# endif

# define NAME "Fractol"

# include "structs.h"
# include "draw.h"
# include "utils.h"
# include "error.h"
# include "hook.h"
# include "math.h"

# include <stdlib.h>
# include <stdio.h>

t_data					*init(int ac, char **av, int w, int h);
void					init_frame(t_frame *frame);

int						chk_julia(t_data *data, int ac, char **av);
int						chk_burning_ship(t_data *data, int ac, char **av);
int						chk_mandelbrot(t_data *data, int ac, char **av);

void					fractol(t_data *data);
int						fractol_hook(void *data);

void					free_data(t_data *data);

#endif
