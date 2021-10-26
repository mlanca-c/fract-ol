/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:23:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/26 12:23:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
t_complex	get_complex(int x, int y, t_view *view)
{
	t_complex	number;

	number.re = ((double)x - view->x_max) / view->zoom;
	number.im = ((double)y - view->y_max) / view->zoom;
	return (number);
}
