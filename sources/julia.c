/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:19:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/19 22:06:29 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
t_complex	get_complex_julia(int x, int y, t_view *view)
{
	t_complex	number;

	number.re = ((double)x - view->x_max) / view->zoom;
	number.im = ((double)y - view->y_max) / view->zoom;
	return (number);
}

/*
*/
t_pixel	julia_set(int x, int y, t_view *view)
{
	t_pixel		pixel;
	t_complex	z;
	t_complex	temp;
	double		i;

	i = 0;
	z = get_complex_julia(x, y, view);
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
