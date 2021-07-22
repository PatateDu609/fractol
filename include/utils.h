/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 03:09:23 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 06:35:10 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

# include "structs.h"

void		error(char *msg);
void		*chk_non_null(void *dat, char *msg);
t_complex	get_complex(t_frame frame, uint16_t x, uint16_t y);
t_complex	make_complex(double r, double i);
void		compute_gradient(t_gradient *g);
void		usage(void);

int			ft_isspace(char c);
int			ft_isdigit(char c);
int			ft_iscomplex(char *arg);
int			ft_strcmp(const char *s1, const char *s2);

int			ft_atoi(char *arg);
double		parse_real(char **arg);
t_complex	parse_complex(char *arg);
char		*ft_tolower(char *s);

#endif
