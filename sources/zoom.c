/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:47:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/08/02 11:47:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
void	zoom_in(t_data *data, int x, int y)
{
	t_img	new_img;
	double	zoom;

	new_img.img = mlx_new_image(data->mlx, data->max_x, data->max_y);
	new_img.addr =  mlx_get_data_addr(new_img.img, &new_img.bpp, &new_img.line_len,
		&new_img.endian);
	zoom = data->zoom * 1.1;
	data->zoom = zoom;
	data->img = &new_img;
	get_fractal(data, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	free(data->img->img);
}

/*
*/
void	zoom_out(t_data *data, int x, int y)
{
	t_img	new_img;
	double	zoom;

	new_img.img = mlx_new_image(data->mlx, data->max_x, data->max_y);
	new_img.addr =  mlx_get_data_addr(new_img.img, &new_img.bpp, &new_img.line_len,
		&new_img.endian);
	zoom = data->zoom / 1.1;
	data->zoom = zoom;
	data->img = &new_img;
	get_fractal(data, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	free(data->img->img);
}
