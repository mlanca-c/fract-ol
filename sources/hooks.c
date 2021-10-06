	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:56:35 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/09/29 10:13:30 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
int	key_hook(int keycode, t_data *data)
{
	(void) data;
	printf("keycode: %x\n", keycode);
	if (keycode == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	return (keycode);
}

/*
*/
int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	data->move->re = x - (WIN_X / 2);
	data->move->im = y - (WIN_Y / 2);
	printf("mousecode: %x\n", mousecode);
	if (mousecode == ZOOM_IN || mousecode == KEY_UP)
		zoom_in(data);
	else if (mousecode == ZOOM_OUT || mousecode == KEY_DOWN)
		zoom_out(data);
	printf("(%d, %d)\n", x, y);
	return (mousecode);
}
