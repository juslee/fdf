/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:54:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/14 19:20:42 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_fdf	fdf;

	fdf.width = WIN_WIDTH;
	fdf.height = WIN_HEIGHT;
	if (argc < 2 || argc > 4)
		return (
			ft_printf("Usage : %s <filename> [ case_size z_size ]\n", argv[0]),
			EXIT_FAILURE);
	if (!parse_map(argv[1], &map))
		return (EXIT_FAILURE);
	if (!init(&fdf, &map))
		return (EXIT_FAILURE);
	mlx_loop_hook(fdf.mlx, render, &fdf);
	mlx_loop(fdf.mlx);
	// render(&fdf);
	// hook_events(fdf);
	// cleanup(fdf);
	return (free_map(&map), EXIT_SUCCESS);
}
