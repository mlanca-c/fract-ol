/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:06:55 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/26 12:44:07 by mlanca-c         ###   ########.fr       */
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
