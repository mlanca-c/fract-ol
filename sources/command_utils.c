/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:37:46 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/20 00:32:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This function is called once the user presses the ESC key of the red cross
** button to close the program's window.
** The function frees all allocated memory and then exits with EXIT_SUCCESS.
**
** @param	t_ctrl	*control	- main struct of the program. Some of the
** 								variables it contains need to be freed.
*/
void	exit_program(t_ctrl *control)
{
	mlx_destroy_window(control->data->mlx, control->data->win);
	mlx_destroy_image(control->data->mlx, control->img->img);
	free(control->img);
	free(control->data);
	free(control->fractal);
	free(control->pixels);
	free(control);
	printf("SUCCESS\n");
	exit(EXIT_SUCCESS);
}

/*
** This function is called if the command line argument is ./fractal --help.
** This will display to the user a list of the available fractals and then exit
** the program with EXIT_SUCCESS.
*/
void	help_message(void)
{
	printf("execution format: ./fractal <fractal_name> [x] [y]\n");
	printf("COLOR_RED List of available fractals:\n\t* Mandelbrot\n\t* Julia\n");
	exit(EXIT_SUCCESS);
}

/*
** This function is called if the command line arguments given by the user are
** not in the correct format:
** 		[./fractol <fractal> [x] [y]
** If so, the error_message() function displays an error message, and exits the
** program with EXIT_FAILURE.
** This function takes no arguments and ends the program when called.
**
** @param	char	*message	- message to be displayed to the user.
*/
void	error_message(char *message)
{
	printf("fractol: %s", message);
	printf("correct format: ./fractol <fractal_name> [x] [y]\n");
	printf("\tadditional info: ./fractol --help\n");
	exit(EXIT_FAILURE);
}

