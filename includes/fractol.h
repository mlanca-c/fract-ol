/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:09:13 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/12 17:40:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# ifndef OS
#  define OS			2
# endif

# ifndef WIDTH
#  define WIDTH			1280.0
# endif

# ifndef HEIGHT
#  define HEIGHT		720.0
# endif

# ifndef PRECISION
#  define PRECISION		255
# endif

# define RES			WIDTH / HEIGHT

# define ZOOM_FACTOR	256;

/*
** Possible Mousecodes:
*/
# define ZOOM_IN		4
# define ZOOM_OUT		5

/*
** Possible Keycode:
*/
# if OS == 1
#  define KEY_LEFT		0xff51	// Move fractal to the left
#  define KEY_RIGHT		0xff53	// Move fractal to the right
#  define KEY_UP		0xff52	// Move the fractal up
#  define KEY_DOWN		0xff54	// Move the fractal down
#  define KEY_ESCAPE	0xff1b	// Exit the window and end the program
#  define KEY_SPACE		0x0020	// Restore image to the initial zoom
#  define KEY_PLUS		0xffab	// Increase precision
#  define KEY_MINUS		0xffad	// Decrease precision
# elif OS == 2
#  define KEY_LEFT		0x007d
#  define KEY_RIGHT		0x007c
#  define KEY_UP		0x007e
#  define KEY_DOWN		0x007b
#  define KEY_ESCAPE	0x0035
#  define KEY_SPACE		0x0031
#  define KEY_PLUS		0x0045
#  define KEY_MINUS		0x004e
# endif

/*
** Possible Colors:
*/
# define BLACK			1
# define RED			2
# define GREEN			3
# define BLUE			4
# define VIOLET			5

/*
** This struct will represent a complex number - z = x + yi.
**
** @param	double	re	- represents the real part of a complex number.
**
** @param	double	im	- represents the imaginary part of a complex number.
*/
typedef struct	s_complex
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
typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/*
** This struct stores all necessary data that allows the fract-ol program to
** interact with MiniLibX.
**
** 	void	*mlx -	pointer returned by the mlx_init() function. This pointer is
** 					the identifier of the connection created by the function.
** 	void	*win -	pointer returned by the mlx_new_window() function. This
** 					pointer is the identifier of the new window created by the
** 					function.
**	t_img	*img -	pointer of struct s_img (t_img). This pointer contains
**					another struct with all the image related variables.
*/
typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
}	t_data;

/*
** This struct stores all necessary information regarding the user's input
** and the type of fractal the program will generate.
**
**	char	*fractal -	this string is either Mandelbrot or Julia, and it will
**						indicate the fractal that will be rendered in the image
**						- img->img.
** 	int		color -	number of the base color the user chooses for the fractal.
** 					1: black and white, 2: red, 3: green, 4: blue, 5: violet.
**					The default color is ...
** 	int		precision -	number of maximum iterations needed to see if a number
**	 					belongs in the Mandelbrot or Julia Set. The bigger the
**	 					number the bigger the pixel precision and the time to
**	 					render the image. The default precisionn is ...
** double	zoom		- zoom factor of the fractal. This variable will be
**						changed according to the mousecodes given by the user.
**						Its default will be ZOOM_FACTOR.
*/
typedef struct	s_fractal
{
	char		*fractal;
	int			color;
	int			precision;
	double		zoom;
	t_complex	julia_params;
	t_data		*data;
}	t_fractal;

/*
** fractol.c Functions
*/
void	get_fractal(t_fractal *fractal);

/*
** hooks.c Functions
*/
int		key_hook(int keycode, t_fractal *fractal);
int		mouse_hook(int mousecode, int x, int y, t_fractal *fractal);

/*
** mandelbrot.c Functions
*/
void	mandelbrot_set(t_fractal *fractal);

/*
** julia.c Functions
*/

/*
** utils.c Functions
*/
int		get_color(int it, int color);
int		create_trgb(int transparency, int red, int green, int blue);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*
** zoom.c Functions
*/

#endif
