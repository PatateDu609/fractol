/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 02:20:15 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/21 04:08:05 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "mlx.h"
# include "structs.h"

typedef struct s_data	t_data;

# if FLOAT == float
#  define LOG2			log2f
#  define SQRT			sqrtf
#  define FLOOR			floorf
# else
#  define LOG2			log2
#  define SQRT			sqrt
#  define FLOOR			floor
# endif

# define ZOOM_FACTOR	1.5
# define MOVE_INC		0.5

t_pixel			rgb(uint8_t r, uint8_t g, uint8_t b);
void			push_image(t_data *data);

#endif
