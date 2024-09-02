/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:54:52 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 10:11:04 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_fdf	fdf;

	fdf.case_size = 20;
	fdf.z_size = 20;
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
	if (!init_fdf(&fdf, &map))
		return (EXIT_FAILURE);
	mlx_loop_hook(fdf.mlx, main_loop, &fdf);
	mlx_hook(fdf.win, 2, 1L << 0, handle_keypress, &fdf);
	mlx_hook(fdf.win, 17, 1L << 17, close_window, &fdf);
	mlx_loop(fdf.mlx);
	return (free_map_point(&map), EXIT_SUCCESS);
}
