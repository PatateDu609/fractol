/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 02:20:15 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 03:12:53 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "mlx.h"
# include "structs.h"

typedef struct s_data	t_data;

# define ZOOM_FACTOR	1.25
# define MOVE_INC		0.75

t_pixel			rgb(uint8_t r, uint8_t g, uint8_t b);
void			push_image(t_data *data);

#endif
