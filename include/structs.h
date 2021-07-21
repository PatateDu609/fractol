/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:40:10 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/21 02:02:28 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <inttypes.h>

# ifndef FLOAT
#  define FLOAT float
# endif

typedef union u_pixel
{
	struct {
		uint8_t			b;
		uint8_t			g;
		uint8_t			r;
		uint8_t			a;
	};
	uint32_t			raw;
}						t_pixel;

typedef struct s_frame
{
	FLOAT				r_min;
	FLOAT				r_max;
	FLOAT				i_min;
	FLOAT				i_max;
	uint16_t			w;
	uint16_t			h;
}						t_frame;

typedef struct s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct s_gradient
{
	int					pts;
	FLOAT				*points;
	t_pixel				*colors;

	int					size;
	t_pixel				*comp;
}						t_gradient;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	void				*mlx_img;

	t_pixel				*image;

	t_frame				frame;
	int					max_it;
	t_gradient			g;

	FLOAT				zoom;
}						t_data;

#endif
