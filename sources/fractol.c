/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:02:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/12 19:02:25 by mlanca-c         ###   ########.fr       */
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
	printf("[./fractol <fractal> [x] [y] [-c <color>]\n");
	exit(1);
}

/*
** This function validates the command line arguments given by the user. This
** input has to follow a format:
** 		[./fractol <fractal> [x] [y] [-c <color>]
** If the format of the input is incorrect, then the error_message() function is
** called and exits the program with EXIT_FAILURE.
**
** @param	int			argc		- number of command line arguments.
** @param	char		**argc		- command line arguments given by the user.
** @param	t_fractal	*fractal	- This struct stores all necessary data that
** 									will later on define the type and
**									characteristics of the fractal.
*/
void	init_input(int argc, char **argv, t_fractal *fractal)
{
	int	i;

	if (ft_strcmp(argv[1], "Mandelbrot") && ft_strcmp(argv[1], "Julia"))
		error_message();
	fractal->fractal = argv[1];
	fractal->color = VIOLET;
	fractal->precision = PRECISION;
	fractal->zoom = ZOOM_FACTOR;
	fractal->julia_params.re = 0;
	fractal->julia_params.im = 0;
	i = 2;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-c") && argc > i + 1
			&& ft_str_isnumeric(argv[++i]))
			fractal->color = ft_atoi(argv[i]);
		i++;
	}
}

/*
** This function chooses which function the program will go to according with
** the user's input.
** The get_fractal() function can either move the processing to mandelbrot_set()
** function or the julia_set() function.
**
** @param	t_data	*data	- struct that stores all necessary data that allows
** 							the program to interact with MiniLibX.
*/
void	get_fractal(t_fractal *fractal)
{
	if (fractal->fractal[0] == 'M')
		mandelbrot_set(fractal);
	/*
	else
		julia_set();
	*/
}

/*
** This function is the main function of the project.
** The main() function will initialize all the MiniLibX functionalities needed
** for the creation of an image and a window. It will also analyse the user's
** input given in the form of command line arguments - such as the request of
** the chosen fractal, its precision and color, for example.
** Once the input and the MiniLibX is initialize the function will call the
** get_fractal() function which will choose the correct function to generate the
** correct fractal.
**
** @param	int		argc	- number of command line arguments.
** @param	char	**argc	- command line arguments given by the user.
*/
int	main(int argc, char **argv)
{
	t_data		data;
	t_img		img;
	t_fractal	fractal;

	if (argc < 2)
		error_message();
	init_input(argc, argv, &fractal);
	data.mlx = mlx_init();
	img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &(img.bpp),
		&(img.line_len), &(img.endian));
	data.img = &img;
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, argv[1]);
	fractal.data = &data;
	get_fractal(&fractal);
	mlx_key_hook(data.win, key_hook, &fractal);
	mlx_mouse_hook(data.win, mouse_hook, &fractal);
	mlx_put_image_to_window(data.mlx, data.win, data.img->img, 0, 0);
	mlx_loop(data.mlx);
	exit(EXIT_FAILURE);
}
