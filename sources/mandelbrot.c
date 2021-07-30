/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:07:12 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/30 18:10:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
int	get_color(int it, int color)
{
	static double	mix = 19;

	if (color == 1)
		color = create_trgb(0, 20.5 * it, 20.5 * it, 20.5 * it);
	else if (color == 2)
		color = create_trgb(0, 255, 20.5 * it, 0);
	else if (color == 3)
		color = create_trgb(0, 0, 20.5 * it, 0);
	else if (color == 4)
		color = create_trgb(0, 0, 0, 20.5 * it);
	else if (color == 5)
		color = mix * it * 100000;
	else
		color = create_trgb(0, 40.5 * it, 20.5 * it, 255);
	return (color);
}

/*
*/
int	get_iterations(int precision, t_formula *formula, double zoom)
{
	int		iterations;
	double	temporary;

	iterations = 0;
	while (pow(formula->z_real, 2.0) + pow(formula->z_imaginary, 2.0) < 4.0
		&& iterations < precision)
	{
		temporary = pow(formula->z_real, 2.0) - pow(formula->z_imaginary, 2.0)
			+ (formula->c_real / (1920 / (2.0 / zoom)));
		formula->z_imaginary = 2.0 * formula->z_real * formula->z_imaginary
			+ (formula->c_imaginary / (1080 / (2.0 / zoom)));
		formula->z_real = temporary;
		iterations++;
	}
	return (iterations);
}

/*
 * This function iterates every pixel of the image created in fractol.c main()
 * function and checks if such pixel belongs to the mandelbrot set or not. Then
 * it applies the zoom changes to the image.
*/
void	mandelbrot_set(t_data *data, double zoom)
{
	int			iterations;
	t_formula	formula;
	double		x;
	double		y;

	x = 0;
	while (x < data->max_x)
	{
		y = 0;
		while (y < data->max_y)
		{
			formula.c_real = x - (data->max_x / 2);
			formula.c_imaginary = y - (data->max_y / 2);
			formula.z_real = 0;
			formula.z_imaginary = 0;
			iterations = get_iterations(data->input->precision, &formula, zoom);
			if (iterations < data->input->precision)
				my_mlx_pixel_put(data->img, x, y,
					get_color(iterations, data->input->color));
			y++;
		}
		x++;
	}
}
