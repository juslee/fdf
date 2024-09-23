/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:54:52 by welee             #+#    #+#             */
/*   Updated: 2024/09/23 13:36:52 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"
#include <math.h>

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_map	map;

	fdf = (t_fdf){0};
	map = (t_map){0};
	if (argc < 2 || argc > 4)
		return (error_args(argv[0], &fdf));
	if (!init_fdf(&fdf))
		return (EXIT_FAILURE);
	if (!parse_args(argc, argv, &fdf))
		return (EXIT_FAILURE);
	if (!parse_map(argv[1], &map))
		return (free_fdf(&fdf), EXIT_FAILURE);
	fdf.map = &map;
	if (!init_mlx(&fdf))
		return (EXIT_FAILURE);
	if (!init_image(&fdf))
		return (EXIT_FAILURE);
	fdf.rot = (t_rotation){-90 * M_PI / 180, 0, 0};
	if (!init_isometric(&fdf))
		return (EXIT_FAILURE);
	if (!init_hooks(&fdf))
		return (EXIT_FAILURE);
	return (free_fdf(&fdf), EXIT_SUCCESS);
}
