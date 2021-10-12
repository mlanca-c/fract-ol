/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:17:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/06 12:39:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
void	zoom_in(t_data *data)
{
	data->zoom *= 1.5;
	get_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

/*
*/
void	zoom_out(t_data *data)
{
	data->zoom /= 1.5;
	get_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
