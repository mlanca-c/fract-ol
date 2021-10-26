/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:19:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/26 13:49:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This function calculates a pixel for the Julia set using the formula
** Z(n + 1) = Z(n) ^ 2 + C.
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
** 		- The julia_set() function returns a struct s_pixel - t_pixel - variable
** 		that represents a pixel on the screen and its iteration value.
*/
t_pixel	julia_set(int x, int y, t_view *view)
{
	t_pixel		pixel;
	t_complex	z;
	t_complex	temp;
	double		i;

	i = 0;
	z = get_complex(x, y, view);
	while (z.re * z.re + z.im * z.im < (1 << 8) && i < view->precision)
	{
		temp.re = z.re * z.re - z.im * z.im + view->mouse.re;
		temp.im = z.re * z.im * 2 + view->mouse.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			i = view->precision;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		i++;
	}
	pixel.coord = z;
	pixel.iteration = i;
	return (pixel);
}
