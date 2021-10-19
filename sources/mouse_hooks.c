/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:54:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/20 00:47:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_ctrl *control)
{
	(void) x;
	(void) y;
	if (mousecode == ZOOM_IN)
		control->view.zoom *= 1.05;
	else if (mousecode == ZOOM_OUT)
		control->view.zoom /= 1.05;
	fractal_render(control);
	return (mousecode);
}
