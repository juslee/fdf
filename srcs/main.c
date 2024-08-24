/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:54:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 18:27:50 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"

#define ESC_KEY 65307
#define PLUS_KEY 112
#define MINUS_KEY 109
#define LEFT_KEY 65361
#define UP_KEY 65362
#define RIGHT_KEY 65363
#define DOWN_KEY 65364
#define ROTATE_X

int	close_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_fdf *data)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_fdf	fdf;

	fdf.width = WIN_WIDTH;
	fdf.height = WIN_HEIGHT;
	fdf.case_size = 30;
	fdf.z_size = 1;
	if (argc < 2 || argc > 4)
		return (
			ft_printf("Usage : %s <filename> [ case_size z_size ]\n", argv[0]),
			EXIT_FAILURE);
	if (argc == 4 && ft_isnumber(argv[2]) && ft_isnumber(argv[3]))
	{
		fdf.case_size = ft_atoi(argv[2]);
		fdf.z_size = ft_atoi(argv[3]);
	}
	if (!parse_map(argv[1], &map))
		return (EXIT_FAILURE);
	if (!init(&fdf, &map))
		return (EXIT_FAILURE);
	mlx_loop_hook(fdf.mlx, main_loop, &fdf);
	mlx_hook(fdf.win, 2, 1L << 0, handle_keypress, &fdf);
	mlx_hook(fdf.win, 17, 1L << 17, close_window, &fdf);
	mlx_loop(fdf.mlx);
	return (free_map(&map), EXIT_SUCCESS);
}
