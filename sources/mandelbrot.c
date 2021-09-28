/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:27:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/08/05 15:57:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iteration(t_complex *z, t_complex *c, t_data *data)
{
	int		it;
	double	temp;

	it = 0;
	//while (z->re * z->re + z->im * z->im < 4 &&
	while (pow(z->re, 2) + pow(z->im, 2) < 4 &&
		it < data->precision)
	{
		temp = pow(z->re, 2) - pow(z->im, 2) + c->re;
		//temp = z->re * z->re - z->im * z->im + c->re;
		z->im = 2.0 * z->re * z->im + c->im;
		z->re = temp;
		it++;
	}
	return (it);
}

void	mandelbrot_set(t_data *data)
{
	t_complex	z;
	t_complex	c;
	double		x;
	double		y;
	int			it;

	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			c.re = (RES * (x - (WIN_X / 2)));
			c.re /= WIN_X / (2.0 / data->zoom);
			c.re += -0.30;
			c.im = y - (WIN_Y / 2);
			c.im /= WIN_Y / (2.0 / data->zoom);
			c.im += -0.64;
			z.re = 0;
			z.im = 0;
			it = mandelbrot_iteration(&z, &c, data);
			if (it < data->precision)
				my_mlx_pixel_put(data->img, x, y,
						get_color(it, data->color));
			y++;
		}
		x++;
	}
}
