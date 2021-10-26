/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:29:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/20 14:49:17 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_ctrl *control)
{
	if (keycode == KEY_ESCAPE)
		exit_program(control);
	else if (keycode == KEY_PLUS)
		control->view.precision *= 2.0;
	else if (keycode == KEY_MINUS)
		control->view.precision /= 2.0;
	else if (keycode == KEY_C)
		control->view.color = (control->view.color + 1) % 4;
	else if (keycode == KEY_SPACE)
		control->view.zoom = ZOOM_FACTOR;
	fractal_render(control);
	return (keycode);
}
