/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:31:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/08/02 11:54:34 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == PLUS_KEY)
	{
		data->input->precision /= 2;
		//get_new_image(data);
	}
	else if (keycode == MINUS_KEY)
	{
		data->input->precision *= 2;
		//get_new_image(data);
	}
	return (keycode);
}

int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	//For coordinates
	if (x && y)
		printf("(%d, %d)\n", x, y);
	if (mouse_code == ZOOM_IN_KEY)
		zoom_in(data, 0, 0);
		//zoom_in(data, x - (1920 / 2), y - (1080 / 2));
	else if (mouse_code == ZOOM_OUT_KEY)
		zoom_out(data, 0, 0);
		//zoom_out(data, x - (1920 / 2), y - (1080 / 2));
	return (mouse_code);
}
