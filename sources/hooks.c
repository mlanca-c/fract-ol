/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:47:16 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/12 17:39:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This functions is called when the user interacts with the MiniLibX window by
** using the keyboard.
** The key_hook() function works when the ESC button, the PLUS and the MINUS
** buttons are pressed, by sending the program to the correct functions
** accordingly.
**
** @param	int		keycode		- represents the key the user pressed when
** 								interating with the fractal image.
** @param	t_data	*data	- struct that stores all necessary data that allows
** 							the program to interact with MiniLibX.
**
** @return
** 		- The key_hook() function returns the 'keycode' variable once its
**		finished.
*/
int		key_hook(int keycode, t_fractal *fractal)
{
	t_data	*data;

	data = fractal->data;
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_image(data->mlx, data->img->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_PLUS)
		fractal->precision *= 2.0;
	else if (keycode == KEY_MINUS)
		fractal->precision /= 2.0;
	else if (keycode == KEY_SPACE)
		fractal->zoom = ZOOM_FACTOR;

	get_fractal(fractal);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (keycode);
}

/*
** This functions is called when the user interacts with the MiniLibX window by
** using the mouse.
** The mouse_hook() function works by calling both zoom_in() and zoom_out()
** functions according to 'mousecode' given by the user.
**
** @param	int		mousecode	- It can either be 4 or 5 if the user zoomed in
** 								or out the image accordingly.
** @param	t_data	*data	- struct that stores all necessary data that allows
** 							the program to interact with MiniLibX.
** @param	int		x	- the x coordinate the mouse was when the user zoomed
** 						the image.
** @param	int		y	- the y coordinate the mouse was when the user zoomed
** 						the image.
**
** @return
** 		- The mouse_hook() function returns the 'mousecode' variable once its
**		finished.
*/
int		mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = fractal->data;
	if (mousecode == ZOOM_IN)
		fractal->zoom *= 1.05;
	else if (mousecode == ZOOM_OUT)
		fractal->zoom /= 1.05;
	get_fractal(fractal);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (mousecode);
}
