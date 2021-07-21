/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 02:16:35 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/20 23:57:46 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef NAME
#  undef NAME
# endif

# define NAME "Fractol"

# include "draw.h"
# include "utils.h"
# include "error.h"
# include "hook.h"
# include "structs.h"
# include "math.h"

# include <stdlib.h>
# include <stdio.h>

t_data					*init(int w, int h);
void					fractol(t_data *data);
int						fractol_hook(void *data);

void					free_data(t_data *data);

#endif
