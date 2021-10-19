/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:06:55 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/19 23:41:25 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This function initiates the struct s_fractal - t_fractal - according to the
** user's input.
**
** @param	char	*str	- command line argument - argv[1] given by the user.
** 							This corresponds to the name of the fractal the user
** 							wants to see. If it isn't "Mandelbrot" or "Julia"
** 							then error_message() function is called. If 'str' is
** 							"--help" the help_message() function is called.
** @returns
** 	The init_fractal() function returns a pointer to the fractal if 'str' is
** 	valid, or calls the error_message() or help_message() function and exits the
** 	program.
*/
t_fractal	*init_fractal(char *str)
{
	t_fractal	*fractal;

	if (!ft_strcmp(str, "--help"))
		help_message();
	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
		error_message(MALLOC_ERROR);
	else if (!ft_strcmp(str, "Mandelbrot"))
		*fractal = (t_fractal){"Mandelbrot", mandelbrot_set};
	else if (!ft_strcmp(str, "Julia"))
		*fractal = (t_fractal){"Julia", julia_set};
	else
		error_message(WRONG_FRACTAL);
	return (fractal);
}

/*
** This function iterates the image, pixel by pixel, using the y * WIDTH + x
** equation and gives and then according to each pixel iteration -
** pixel->iterations, it gives a color to the pixel, which is then put in the
** image using the my_mlx_pixel_put() function.
** At the end of the function the image is uploaded to the window -
** mlx_put_image_to_window()
**
** @param	t_ctrl	*control - main struct of the program that stores all
** 							important variables.
*/
void	pixels_to_image(t_ctrl *control)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < control->width)
	{
		y = 0;
		while (y < control->height)
		{
			color = get_color((control->pixels + y * WIDTH + x)->iteration,
				control->view.precision, control->view.color);
			my_mlx_pixel_put(control->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(control->data->mlx, control->data->win,
		control->img->img, 0, 0);
}

/*
** This function iterates the image, pixel by pixel using the y * WIDTH + x
** equation and calls the fn_fractal function to get the t_pixel struct from
** each pixel in the image.
**
** @param	t_ctrl	*control - main struct of the program that stores all
** 							important variables.
*/
void	fractal_render(t_ctrl *control)
{
	int	x;
	int	y;

	x = 0;
	while (x < control->width)
	{
		y = 0;
		while (y < control->height)
		{
			*(control->pixels + y * WIDTH + x)
						= control->fractal->fn_fractal(x, y, &control->view);
			y++;
		}
		x++;
	}
	pixels_to_image(control);
}
