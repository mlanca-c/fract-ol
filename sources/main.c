/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:45:17 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/26 12:08:07 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This is the main function of the project. The main() function takes an
** argument from the user - in this case the fractal the user wants to see - and
** validates that argument.
** The function focuses on initiating variables:
** 		init_fractal()	- to initiate the t_fractal variable;
** 		init_control()	- to initiate the t_ctrl variable;
** 		init_view()		- to initiate the t_view variable;
** 		init_loop()		- to initiate a loop with the MiniLibX.
** After all is initiate the fractal is rendered, and the fractal_render()
** function is called.
**
** @param	int		argc	- argument counter.
** @param	char	*argv	- command line argument.
*/
int	main(int argc, char **argv)
{
	t_fractal	*fractal;
	t_ctrl		*control;

	if (argc < 2)
		error_message(INVALID_ARGS);
	fractal = init_fractal(argv[1]);
	control = init_control(fractal->name);
	control->fractal = fractal;
	init_view(control);
	fractal_render(control);
	init_loop(control);
	return (0);
}
