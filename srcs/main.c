/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:54:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 19:32:41 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"
#include "transform.h"

#define ESC_KEY 65307 // esc
#define PLUS_KEY 112 // p
#define MINUS_KEY 109 // m
#define LEFT_KEY 65361 // left
#define UP_KEY 65362 // up
#define RIGHT_KEY 65363 // right
#define DOWN_KEY 65364 // down
#define ROTATE_X

int	close_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_fdf *fdf)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY)
		close_window(fdf);
	else if (keycode == PLUS_KEY)
		update_scaling(&fdf->view, (t_scaling){1.1, 1.1, 1.1});
	else if (keycode == MINUS_KEY)
		update_scaling(&fdf->view, (t_scaling){0.9, 0.9, 0.9});
	else if (keycode == LEFT_KEY)
		fdf->offset_x -= 10;
	else if (keycode == RIGHT_KEY)
		fdf->offset_x += 10;
	else if (keycode == UP_KEY)
		fdf->offset_y -= 10;
	else if (keycode == DOWN_KEY)
		fdf->offset_y += 10;
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_fdf	fdf;

	fdf.width = WIN_WIDTH;
	fdf.height = WIN_HEIGHT;
	fdf.case_size = 20;
	fdf.z_size = 20;
	fdf.zoom = 1;
	fdf.offset_x = WIN_WIDTH / 2;
	fdf.offset_y = WIN_HEIGHT / 2;
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
