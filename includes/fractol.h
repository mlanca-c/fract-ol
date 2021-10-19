/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:29:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/20 00:48:52 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ansi.h"
# include "messages.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# ifndef OS
#  define OS			2
# endif

# ifndef SCALE_FACTOR
#  define SCALE_FACTOR	250.0
# endif

# ifndef WIDTH
#  define WIDTH			1280
# endif

# ifndef HEIGHT
#  define HEIGHT		720
# endif

# ifndef PRECISION
#  define PRECISION		50
# endif

# define ZOOM_FACTOR	250;

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
#  define KEY_C			0x		// Change the color
#  define KEY_H			0x		// Get help menu
#  define KEY_J			0x		// Get different Julia sets
# elif OS == 2
#  define KEY_LEFT		0x007d
#  define KEY_RIGHT		0x007c
#  define KEY_UP		0x007e
#  define KEY_DOWN		0x007b
#  define KEY_ESCAPE	0x0035
#  define KEY_SPACE		0x0031
#  define KEY_PLUS		0x0045
#  define KEY_MINUS		0x004e
#  define KEY_C			0x0008
#  define KEY_H			0x0004
#  define KEY_J			0x0026
# endif

/*
** Possible Colors:
*/
# define VIOLET			0
# define BLACK			1
# define RED			2
# define GREEN			3
# define BLUE			4

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
** This struct is a pixel on the screen.
** Every pixel is going to be iterated a certain amount of times - 'iterations'.
** The value of iteration will later define the pixel's color.
**
** @param	t_complex	coord	- coordinates (x, y) of a pixel in the form of a
** 								complex number (real, imaginary);
** @param	int			iteration	- number of times the pixel was iterated by
** 									the fractal formula.
*/
typedef struct	s_pixel
{
	t_complex	coord;
	int			iteration;
}	t_pixel;

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
}	t_data;

/*
** This struct contains all necessary values the program will need about the
** image and limits of the fractal.
**
** @param	double	x_max	- limit of the real axis to the right side.
** @param	double	x_min	- limit of the real axis to the left side.
** @param	double	y_max	- limit of the imaginary axis up.
** @param	double	y_min	- limit of the imaginary axis down.
** @param	double	zoom	- zoom of the fractal.
** @param	int		precision	- precision of the fractal.
** @param	t_complex	mouse	- coordinate of the mouse.
*/
typedef struct	s_view
{
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		zoom;
	int			precision;
	t_complex	mouse;
	int			color;
}	t_view;

/*
*/
typedef	t_pixel	(* t_fn_fractal)(int x, int y, t_view *view);

/*
** This struct stores all necessary information regarding the user's input
** and the type of fractal the program will generate.
**
**	char	*name -	this string is either Mandelbrot or Julia, and it will
**						indicate the fractal that will be rendered in the image
**						- img->img.
**	t_fn_fractal	fn_fractal	- function pointer to the fractal_function.
*/
typedef struct	s_fractal
{
	char			*name;
	t_fn_fractal	fn_fractal;
}	t_fractal;

/*
** This is the main struct of the project. It contains all other structs: mlx
** related structs - img, data; and fractal related struct - fractal and view.
**
** @param	t_img	*img	- pointer to the image of the fractal.
** @param	t_data	*data	- pointer to the MiniLibX struct.
** @param	t_pixel	*pixels	- struct s_pixel array where each pixel represents a
** 							has its coordinates and its iteration.
*/
typedef struct	s_control
{
	t_img		*img;
	t_data		*data;
	t_fractal	*fractal;
	t_pixel		*pixels;
	t_view		view;
	int			width;
	int			height;
}	t_ctrl;

/*
** fractol.c Functions
*/
t_fractal	*init_fractal(char *str);
void		fractal_render(t_ctrl *control);
void		pixels_to_image(t_ctrl *control);

/*
** view.c Functions
*/
void		init_view(t_ctrl *control);

/*
** mandelbrot.c Functions
*/
t_pixel		mandelbrot_set(int x, int y, t_view *view);

/*
** julia.c Functions
*/
t_pixel		julia_set(int x, int y, t_view *view);

/*
** command_utils.c Functions
*/
void		help_message(void);
void		error_message(char *str);
void		init_loop(t_ctrl *control);
void		exit_program(t_ctrl *control);

/*
** minilibx_utils.c Functions
*/
int			create_trgb(int transparency, int red, int green, int blue);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*
** control.c Functions
*/
t_ctrl		*init_control(char *name);
void		*ft_malloc(int size);

/*
** color.c Functions
*/
int			get_color(int iteration, int precision, int color);

/*
** mouse_hook.c Functions
*/
int			mouse_hook(int mousecode, int x, int y, t_ctrl *control);

int		key_hook(int keycode, t_ctrl *control);

#endif
