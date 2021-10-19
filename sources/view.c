/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:30:43 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/20 00:29:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This function initiates the struct s_view (t_view) of controls.
**
** @param	t_ctrl	*control	- struct that stores all the variables of the
** 								project.
*/
void	init_view(t_ctrl *control)
{
	control->view.x_max = (float)(WIDTH / 2.0);
	control->view.x_min = (float)(-1 * (WIDTH / 2.0));
	control->view.y_max = (float)(HEIGHT / 2.0);
	control->view.y_min = (float)(-1 * (HEIGHT / 2.0));
	control->view.zoom = SCALE_FACTOR;
	control->view.precision = PRECISION;
	control->width = WIDTH;
	control->height = HEIGHT;
	control->view.mouse = (t_complex){-0.835f, -0.232f};
	control->view.color = 0;
}
