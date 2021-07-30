/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:47:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/30 16:58:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
void	zoom_in(t_data *data)
{
	t_img	new_img;
	double	zoom;

	new_img.img = mlx_new_image(data->mlx, data->max_x, data->max_y);
	new_img.addr =  mlx_get_data_addr(new_img.img, &new_img.bpp, &new_img.line_len,
		&new_img.endian);
	zoom = data->zoom * 2;
	data->zoom = zoom;
	data->img = &new_img;
	get_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	free(data->img->img);
}
