/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:40:10 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 13:55:58 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <inttypes.h>

typedef enum e_fractal
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}						t_fractal;

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
	double				r_min;
	double				r_max;
	double				i_min;
	double				i_max;
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
	double				*points;
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
	t_fractal			set;
	t_complex			julia_c;
	t_gradient			g;

	double				zoom;
	int					autozoom;
	int					shift;
	int					dx;
	int					dy;
}						t_data;

#endif
