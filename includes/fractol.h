/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:52:34 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/08/05 14:24:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# ifndef WIN_X
#  define WIN_X		1920.0
# endif

# ifndef WIN_Y
#  define WIN_Y		1080.0
# endif

# define RES	WIN_X / WIN_Y

# ifndef ZOOM
#  define ZOOM		1.5
# endif

# define ZOOM_IN	4
# define ZOOM_OUT	5

# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_ESCAPE	65307
# define KEY_SPACE	32
# define KEY_PLUS	65451
# define KEY_MINUS	65453

# define BLACK		1
# define RED		2
# define GREEN		3
# define BLUE		4
# define LIGHT_BLUE	5
# define VIOLET		6

/*
** This struct defines a complex number (x + yi), where x is the real part and y
** the imaginary part.
**
** 	double	re	- real part of the complex number.
** 	double	im	- imaginary part of the complex number.
*/
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

/*
** This struct stores data related to the image the program is creating.
**
** 	void	*img -		image, pointer returned by the mlx_new_image() function.
** 						This pointer is the identifier of the fractal image the
** 						program creates.
** 	char	*addr -		address, information regarding the image.
** 	int		bpp -		bits per pixel, this number represents the number of
** 						bits exist per pixel.
** 	int		line_len -	line length, this number represents the number of bytes 
** 						used to store one line of the image in memory.
** 	int		endian -	endian, tells ypu wether the pixel color in the image
** 						needs to be stored in little endian (endian = 0) or big
** 						endian (endian = 1).
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
** This struct stores all the necessary data for the project.
**
** 	void	*mlx -	pointer returned by the mlx_init() function. This pointer is
** 					the identifier of the connection created by the function.
** 	void	*win -	pointer returned by the mlx_new_window() function. This
** 					pointer is the identifier of the new window created by the
** 					function.
**	t_img	*img -	pointer of struct s_img (t_img). This pointer contains
**					another struct with all the image related variables.
**	char	*fractal -	this string is either Mandelbrot or Julia, and it will
**						indicate the fractal that will be rendered in the image
**						- img->img.
** 	int		color -	number of the base color the user chooses for the fractal.
** 					1: black and white, 2: red, 3: green, 4: blue,
** 					5: light blue, 6: violet, default: yellow.
** 	int		precision -	number of maximum iterations needed to see if a number
**	 					belongs in the Mandelbrot or Julia Set. The bigger the
**	 					number the bigger the pixel precision and the time to
**	 					render the image.
*/
typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		*fractal;
	int			color;
	int			precision;
	double		zoom;
	t_complex	*move;
	t_complex	*n;
}	t_data;

/*
** fractol.c Functions
*/
void	get_fractal(t_data *data);

/*
** fractol_utils.c Functions
*/
int		get_color(int it, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_trgb(int transparency, int red, int green, int blue);

/*
** hooks.c Functions
*/
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int mousecode, int x, int y, t_data *data);

/*
** input.c Functions
*/
void	error_message(void);
void	input_init(int argc, char **argv, t_data *data);

/*
** mandelbrot.c Functions
*/
void	mandelbrot_set(t_data *data);

/*
** zoom.c Functions
*/
void	zoom_in(t_data *data);
void	zoom_out(t_data *data);

#endif
