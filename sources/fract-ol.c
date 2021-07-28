/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:28:38 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/27 18:05:38 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_data *data)
{
	int x_max = 1920;
	int y_max = 1080;
	int	x, y, real, imag;
	int	ray = 250;

	x = 0;
	while (x < x_max)
	{
		y = 0;
		while (y < y_max)
		{
			real = x - (x_max / 2);
			imag = y - (y_max / 2);
			if (pow(real, 2) + pow(imag, 2) <= pow(ray, 2))
				my_mlx_pixel_put(data, x, y, COLOR);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Circle!");
	data.image = mlx_new_image(data.mlx, 1920, 1080);
	data.address = mlx_get_data_addr(data.image, &data.bits_per_pixel,
		&data.line_length, &data.endian);
	draw_circle(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.image, 0, 0);
	mlx_loop(data.mlx);
}
