/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:54:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/11 21:52:49 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	// t_fdf	*fdf;

	if (argc < 2 || argc > 4)
	{
		ft_printf("Usage : %s <filename> [ case_size z_size ]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	map = parse_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	// fdf = init_fdf(map);
	// if (!fdf)
	// {
	// 	free_map(map);
	// 	ft_printf("Error: Failed to initialize fdf");
	// 	return (EXIT_FAILURE);
	// }
	// render(fdf);
	// hook_events(fdf);
	// cleanup(fdf);
	return (0);
}
