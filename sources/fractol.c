/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:52:18 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/10/06 12:38:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
*/
void	get_fractal(t_data *data)
{
	if (data->fractal[0] == 'M')
		mandelbrot_set(data);
	/*
	else if (data->fractal[0] == 'J')
		julia_set(data);
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
**
** @return
** 	- The main() function will return 1 in case of error - if MiniLibX didn't
** 	perform as intended or the user's input wasn't in the correct format - and
** 	it will return 0 in case of success.
*/
int	main(int argc, char *argv[])
{
	t_img		img;
	t_data		data;
	t_complex	move;

	if (argc < 2)
		error_message();
	input_init(argc, argv, &data);
	data.mlx = mlx_init();
	move.re = 0;
	move.im = 0;
	data.move = &move;
	data.zoom = 1.0;
	img.img = mlx_new_image(data.mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &(img.bpp),
		&(img.line_len), &(img.endian));
	data.img = &img;
	data.win = mlx_new_window(data.mlx, WIN_X, WIN_Y, argv[1]);
	get_fractal(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img->img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
