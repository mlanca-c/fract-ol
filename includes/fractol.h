/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:31:45 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/30 13:17:43 by mlanca-c         ###   ########.fr       */
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
 * This struct represents the input the program receives from the user -
 * command line arguments.
 * 	char	*fractal	- fractal the user wants to see. It can either be
 * 						the Mandelbrot or the Julia Set.
 * 	int		c_real		- this integer only contains values in case its the
 * 						Julia set.
 * 	int		c_imaginary	- this integer only contains values in case its the
 * 						Julia set.
 * 	int		precision	- This is the number of iterations the fractal has.
 * 						In case this number isn't specified, the default is 255.
 * 	int		color		- This is the base color of the fractal. In case this
 * 						number isn't specified, the default is 0x00FF0000.
*/
typedef struct s_input
{
	char	*fractal;
	int		c_real;
	int		c_imaginary;
	int		precision;
	int		color;
}	t_input;

/*
*/
typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	int			max_x;
	int			max_y;
	t_input		*input;
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
