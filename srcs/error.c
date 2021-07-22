/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 03:07:27 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 06:22:33 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*chk_non_null(void *dat, char *msg)
{
	if (dat)
		return (dat);
	error(msg);
	return (NULL);
}

void	error(char *msg)
{
	printf("Error: %s\n", msg);
	exit(1);
}
