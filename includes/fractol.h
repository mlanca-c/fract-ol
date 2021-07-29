/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:31:45 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/29 15:58:41 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>

# define ZOOM_IN_KEY 4
# define ZOOM_OUT_KEY 5
# define ESC_KEY 0xff1b
# define PLUS_KEY 0xffab
# define MINUS_KEY 0xffad

/*
*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/*
*/
typedef struct s_formula
{
	double	c_real;
	double	c_imaginary;
	double	z_real;
	double	z_imaginary;
}	t_formula;

/*
*/
typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			precision;
	char		*fractal;
	t_img		*img;
	int			max_x;
	int			max_y;
}	t_data;

/*
** hooks.c Functions
*/
int		key_hook(int keycode, t_data *data);

/*
** mandelbrot.c Functions
*/
void	mandelbrot_set(t_data *data);

/*
** utils.c Functions
*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_trgb(int transparency, int red, int green, int blue);

#endif
