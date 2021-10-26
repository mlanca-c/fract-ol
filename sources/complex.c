/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:23:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/26 14:37:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This function calculates, based on the x and y coordinates the pixel
** coordinates the mandelbrot_set() and the julia_set() functions will iterate.
**
** @param	int		x		- x coordinate of the pixel that is going to be
** 							calculated.
** @param	int		y		- y coordinate of the pixel that is going to be
** 							calculated.
** @param	t_view	*view	- struct that contains all necessary values the
** 							program will need about the image and the limits of
** 							the fractal.
**
** @return
** 		- The get_complex() function returns a struct s_complex - t_complex -
** 		variable that represents a complex number, based on the x and y
** 		coordinates given as parameters and the image's limits - view
*/
t_complex	get_complex(int x, int y, t_view *view)
{
	t_complex	number;

	number.re = ((double)x - view->x_max) / view->zoom;
	number.im = ((double)y - view->y_max) / view->zoom;
	return (number);
}
