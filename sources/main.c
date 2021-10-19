/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:45:17 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/19 22:06:02 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
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
