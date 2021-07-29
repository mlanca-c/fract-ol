/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:10:57 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/29 16:16:48 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_fractal(t_data *data)
{
	if (ft_strcmp(data->fractal, "Mandelbrot"))
		mandelbrot_set(data);
	else
		printf("Wrong Fractal\n");
}

/*
*/
int	main(int argc, char **argv)
{
	t_data		data;
	t_img		img;

	if (argc < 2)
		return (1);
	data.mlx = mlx_init();
	data.max_x = 1920;
	data.max_y = 1080;
	data.precision = 255;
	data.win = mlx_new_window(data.mlx, data.max_x, data.max_y, argv[1]);
	img.img = mlx_new_image(data.mlx, data.max_x, data.max_y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	data.img = &img;
	get_fractal(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img->img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
