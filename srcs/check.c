/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 05:49:28 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 06:26:16 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == '\f');
}

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_iscomplex(char *arg)
{
	while (*arg)
	{
		if (*arg == 'i')
			return !*(arg + 1);
		if (!ft_isdigit(*arg) && !ft_isspace(*arg) && *arg != '.'
			&& *arg != '-' && *arg != '+')
			return (0);
		arg++;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
