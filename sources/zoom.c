/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:17:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/08/04 19:28:18 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
void	zoom_in(t_data *data)
{
	t_img	img;

	img.img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &(img.bpp),
		&(img.line_len), &(img.endian));
	data->img = &img;
	data->zoom *= 1.7;
	get_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	free(data->img->img);
}

/*
*/
void	zoom_out(t_data *data)
{
	t_img	img;

	img.img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &(img.bpp),
		&(img.line_len), &(img.endian));
	data->img = &img;
	data->zoom /= 1.7;
	get_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	free(data->img->img);
}
