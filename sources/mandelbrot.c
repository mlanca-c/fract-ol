/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:19:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/20 14:50:29 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
t_complex	get_complex(int x, int y, t_view *view)
{
	t_complex	number;

	number.re = ((double)x - view->x_max) / view->zoom;
	number.im = ((double)y - view->y_max) / view->zoom;
	return (number);
}

/*
*/
t_pixel	mandelbrot_set(int x, int y, t_view *view)
{
	t_pixel		pixel;
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	double		i;

	i = 0;
	z = get_complex(x, y, view);
	c = z;
	while (z.re * z.re + z.im * z.im < (1 << 8) && i < view->precision)
	{
		temp.re = z.re * z.re - z.im * z.im + c.re;
		temp.im = z.re * z.im * 2 + c.im;
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
