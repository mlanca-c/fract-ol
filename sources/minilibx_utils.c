/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:39:43 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/20 00:36:41 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * This function initiates a loop with MiniLibX that lets the window open while
 * the program is running. It also manages the MiniLibX hooks.
 *
 * @param	t_ctrl	*control	- this struct 
*/
void	init_loop(t_ctrl *control)
{
	mlx_key_hook(control->data->win, key_hook, &control);
	mlx_mouse_hook(control->data->win, mouse_hook, control);
	mlx_loop(control->data->mlx);
}

/*
** This function creates a TRGB color - int - based on its levels of
** transparency, red, green and blue.
** Each byte contains 2^8 - 256 values, and RGB values range from 0 to 255, we
** can perfectly fit a integer (as an int is 4 bytes).
** In order to set the values bit shifting is used.
**
** @param	int	transparency	- level of transparency 'color' should have.
** @param	int	red		- level (int) of red 'color' should have.
** @param	int	green	- level (int) of green 'color' should have.
** @param	int	blue	- level (int) of blue 'color' should have.
**
** @return
** 	- The create_trgb() function returns an integer with the indicated values of
** 	transparency, red, green and blue given as parameters. This int symbolizes a
** 	color a certain pixel is suppose to have.
*/
int	create_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

/*
** This function mimics the behaviour of tghe mlx_pixel_put() function.
** It calculates the offset and then it adds a color. It is more efficient to
** create the fractal image like this, instead of using the mlx_pixel_put()
** function of the MiniLibX.
**
** @param	int	x	- x coordinate of the pixel we want to add to the image.
** @param	int	y	- y coordinate of the pixel we want to add to the image.
** @param	int	color	- color of the pixel we want to add to the image.
*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

void	my_mlx_text_put();
