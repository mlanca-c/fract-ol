/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:31:45 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/27 18:07:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
#include <stdio.h>

# define COLOR 0xFFFFFFFF
# define ESC_KEY 0xff1b
# define PLUS_KEY 0xffab
# define MINUS_KEY 0xffad
# define ZOOM_IN_KEY 4
# define ZOOM_OUT_KEY 5

/*
*/
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*
*/
typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

int	key_hook(int keycode, t_data *data);

#endif
