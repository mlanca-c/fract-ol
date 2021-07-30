/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:10:57 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/30 17:05:32 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * When called this function displays an error message and exits the program.
*/
void	error_message(void)
{
	printf("fractol: invalid arguments.\n");
	printf("correct format: ");
	printf("[./fractol <fractal> [x] [y] [-p <precision>] [-c <color>]\n");
	exit(1);
}

/*
*/
int	get_input_fractal(char **argv, int argc, t_input *input)
{
	if (!ft_strcmp(argv[1], "Mandelbrot"))
	{
		input->fractal = argv[1];
		input->c_real = 0;
		input->c_imaginary = 0;
		return (2);
	}
	else if (!ft_strcmp(argv[1], "Julia") && argc > 3
		&& ft_str_isnumeric(argv[2]) && ft_str_isnumeric(argv[3]))
	{
		input->fractal = argv[1];
		input->c_real = ft_atoi(argv[2]);
		input->c_imaginary = ft_atoi(argv[3]);
		return (4);
	}
	else
		error_message();
	return (0);
}

/*
*/
t_input	*init_input(char **argv, int argc, t_input *input)
{
	int		i;

	i = get_input_fractal(argv, argc, input);
	input->precision = 255;
	input->color = 0x0000FF00;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-p") && argc > i + 1
			&& ft_str_isnumeric(argv[++i]))
			input->precision = ft_atoi(argv[i]);
		else if (!ft_strcmp(argv[i], "-c") && argc > i + 1
			&& ft_str_isnumeric(argv[++i]))
			input->color = ft_atoi(argv[i]);
		else
			error_message();
		i++;
	}
	return (input);
}

/*
*/
void	get_fractal(t_data *data)
{
	if (!ft_strcmp(data->input->fractal, "Mandelbrot"))
		mandelbrot_set(data, data->zoom);
	//else if (!ft_strcmp(data->input->fractal, "Julia"))
	//	julia_set();
}

/*
*/
int	main(int argc, char **argv)
{
	t_data		data;
	t_input		input;
	t_img		img;

	if (argc < 2)
		error_message();
	data.input = init_input(argv, argc, &input);
	data.mlx = mlx_init();
	data.max_x = 1920;
	data.max_y = 1080;
	data.zoom = 0.5;
	data.win = mlx_new_window(data.mlx, data.max_x, data.max_y, argv[1]);
	img.img = mlx_new_image(data.mlx, data.max_x, data.max_y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	data.img = &img;
	get_fractal(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, key_hook, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img->img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
