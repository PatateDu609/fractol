/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:53:23 by gboucett          #+#    #+#             */
/*   Updated: 2021/07/22 14:01:37 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# define ESC 			65307
# define UP				65362
# define DOWN			65364
# define RIGHT			65363
# define LEFT			65361
# define SHIFT			65505
# define SCROLL_OUT		5
# define SCROLL_IN		4
# define X				120
# define F				102

void	scroll(t_data *data, double coeff, int x, int y);
void	arrows(t_data *data, int dx, int dy);
int		mouse(int button, int x, int y, void *d);
int		quit(void *d);
int		key_release(int kc, void *d);
int		key_press(int kc, void *d);

#endif
