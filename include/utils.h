/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 03:09:23 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/20 12:14:42 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

# include "structs.h" 

void		*chk_non_null(void *dat, char *msg);
t_complex	get_complex(t_frame frame, uint16_t x, uint16_t y);
void		compute_gradient(t_gradient *g);

#endif
