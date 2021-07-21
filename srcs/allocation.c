/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 03:07:27 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/19 03:11:30 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void *chk_non_null(void *dat, char *msg)
{
	if (dat)
		return dat;
	printf("Error: %s\n", msg);
	exit(1);
}
