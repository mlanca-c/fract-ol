/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:31:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/30 17:03:45 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *data)
{
	(void) data;
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == ZOOM_IN_KEY || keycode == PLUS_KEY)
		zoom_in(data);
	else if (keycode == ZOOM_OUT_KEY || keycode == MINUS_KEY)
		zoom_out(data);
	return (keycode);
}
