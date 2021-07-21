/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:53:23 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/21 17:41:17 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# define ESC 			65307
# define UP				65362
# define DOWN			65364
# define RIGHT			65363
# define LEFT			65361
# define SCROLL_DOWN	5
# define SCROLL_UP		4
# define X				120

int		mouse(int button, int x, int y, void *d);
int		quit(void *d);
int		key_press(int kc, void *d);

#endif
