/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 04:48:55 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 05:59:19 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	skip(char **arg, int *sign)
{
	while (ft_isspace(**arg))
		(*arg)++;
	*sign = 1;
	while (**arg == '-' || **arg == '+')
		if (*(*arg)++ == '-')
			*sign *= -1;
}

int	ft_atoi(char *arg)
{
	int		res;
	int		sign;

	skip(&arg, &sign);
	res = 0;
	while (ft_isdigit(*arg))
		res = res * 10 + *arg++ - '0';
	return (res * sign);
}

double	parse_real(char **arg)
{
	double	res;
	int		e;
	double	j;
	int		sign;

	skip(arg, &sign);
	j = sign;
	e = 1;
	res = 0;
	while (ft_isdigit(**arg) || (e == 1 && **arg == '.'))
	{
		if (*(*arg)++ == '.' && e)
		{
			e = 0;
			continue ;
		}
		res = res * 10. + *(*arg - 1) - '0';
		if (!e)
			j /= 10.;
	}
	return (res * j);
}

t_complex	parse_complex(char *arg)
{
	t_complex	z;
	double		x;
	int			sign;
	char		*tmp;

	tmp = arg;
	x = parse_real(&arg);
	if (*arg == 'i')
	{
		if (arg == tmp)
			x = 1;
		z.i = x;
		arg++;
		return (z);
	}
	else
		z.r = x;
	skip(&arg, &sign);
	skip(&arg, &sign);
	tmp = arg;
	z.i = parse_real(&arg) * sign;
	if (arg == tmp && *arg == 'i')
		z.i = 1;
	return (z);
}

char	*ft_tolower(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s)
	{
		if ('A' < *s && *s < 'Z')
			*s += 32;
		s++;
	}
	return (tmp);
}
