/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:20:33 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/08/05 14:25:25 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This function is called if the command line arguments given by the user are
** not in the correct format:
** 		[./fractol <fractal> [x] [y] [-p <precision>] [-c <color>]
** If so, the error_message() function displays an error message, and exits the
** program with EXIT_FAILURE.
** This function takes no arguments and ends the program when called.
*/
void	error_message(void)
{
	printf("fractol: invalid arguments.\n");
	printf("correct format: ");
	printf("[./fractol <fractal> [x] [y] [-p <precision>] [-c <color>]\n");
	exit(1);
}

/*
** This function validates the command line arguments given by the user. This
** input has to follow a format:
** 		[./fractol <fractal> [x] [y] [-p <precision>] [-c <color>]
** If the format of the input is incorrect, then the error_message() function is
** called and exits the program with EXIT_FAILURE.
**
** @param	int		argc	- number of command line arguments.
** @param	char	**argc	- command line arguments given by the user.
** @param	t_data	data	- struct where the correct information is stored.
**
*/
void	input_init(int argc, char **argv, t_data *data)
{
	int			i;

	if (ft_strcmp(argv[1], "Mandelbrot") && ft_strcmp(argv[1], "Julia"))
		error_message();
	data->fractal = argv[1];
	i = 2;
	data->precision = 255;
	data->color = 42;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-p") && argc > i + 1
			&& ft_str_isnumeric(argv[++i]))
			data->precision = ft_abs(ft_atoi(argv[i]));
		else if (!ft_strcmp(argv[i], "-c") && argc > i + 1
			&& ft_str_isnumeric(argv[++i]))
			data->color = ft_atoi(argv[i]);
		else
			error_message();
		i++;
	}
}
