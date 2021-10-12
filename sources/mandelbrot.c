/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:03:10 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/12 19:03:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_iterations(t_complex c, t_complex z, int precision)
{
	double	temp;
	int		it;

	it = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) < 4.0 && it < precision)
	{
		temp = (pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re;
		z.im = (2.0 * z.re * z.im) + c.im;
		z.re = temp;
		it++;
	}
	return (it);
}

void	mandelbrot_set(t_fractal *fractal)
{
	t_complex	c;
	t_complex	z;
	t_complex	pixel;
	t_complex	limit;
	int			it;

	pixel.re = 0;
	limit.re = WIDTH / 2.0;
	limit.im = HEIGHT / 2.0;
	while (pixel.re < WIDTH)
	{
		pixel.im = 0;
		c.re = (pixel.re - limit.re) / fractal->zoom;
		while (pixel.im < HEIGHT)
		{
			c.im = (limit.im - pixel.im) / fractal->zoom;
			z.re = 0.0;
			z.im = 0.0;
			it = mandelbrot_iterations(c, z, fractal->precision);
			if (it < fractal->precision)
				my_mlx_pixel_put(fractal->data->img, pixel.re, pixel.im,
					get_color(it, fractal->color));
			else
				my_mlx_pixel_put(fractal->data->img, pixel.re, pixel.im,
					create_trgb(0, 0, 0, 0));
			pixel.im++;
		}
		pixel.re++;
	}
}
