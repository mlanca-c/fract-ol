/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:25:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/19 20:28:22 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This function contains the different color equations for the fractals.
**
** @param	int	iteration	- represents the iteration of a certain pixel.
** @param	int	precision	- represents the precision of the fractal.
** @param	int	color		- represents the color of the fractal.
**
** @returns
**	The get_color() function returns the color (int) of the pixel according to
**	its iteration.
*/
int	get_color(int iteration, int precision, int color)
{
	if (iteration >= precision)
		return (create_trgb(0, 0, 0, 0));
	else if (color == RED)
		return (create_trgb(0, 255, 20.5 * iteration, 0));
	else if (color == GREEN)
		return (create_trgb(0, 0, 20.5 * iteration, 0));
	else if (color == BLUE)
		return (create_trgb(0, 0, 0, 20.5 * iteration));
	else if (color == VIOLET)
		return (create_trgb(0, 40.5 * iteration, 20.5 * iteration, 255));
	return (create_trgb(0, 9 * (1 - iteration) * pow(iteration, 3) * 255,
			15 * pow((1 - iteration), 2) * pow(iteration, 2) * 255,
			8.5 * pow((1 - iteration), 3) * iteration * 255));
}
