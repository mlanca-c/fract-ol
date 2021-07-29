/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:12:35 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/29 16:56:22 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
int	get_iterations(t_data *data, t_formula *formula)
{
	int		it;
	double	temporary;

	it = 0;
	while (pow(formula->z_real, 2) + pow(formula->z_imaginary, 2) < 4
		&& it < data->precision)
	{
		temporary = pow(formula->z_real, 2) - pow(formula->z_imaginary, 2)
			+ (formula->c_real / (data->max_x / 5));
		formula->z_imaginary = 2 * formula->z_real * formula->z_imaginary
			+ (formula->c_imaginary / (data->max_y / 5));
		formula->z_real = temporary;
		it++;
	}
	return (it);
}

/*
*/
void	mandelbrot_set(t_data *data)
{
	t_formula	formula;
	int			it;
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
			it = get_iterations(data, &formula);
			if (it < data->precision)
				my_mlx_pixel_put(data->img, x, y, (0x000000 + (it * 10)));
			y++;
		}
		x++;
	}
}
