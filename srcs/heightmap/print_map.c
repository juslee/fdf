/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:17:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:49:04 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "heightmap.h"
#include "ft_printf.h"
#include <stdio.h>

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("%d ", map->z_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_map_point(t_map *map)
{
	int	y;
	int	x;
	int	hex_color;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf("%d", map->map_points[y][x].point.z);
			if (!is_default_color(map->map_points[y][x].color))
			{
				hex_color = color_to_hex(map->map_points[y][x].color);
				ft_printf(",0x%X", hex_color);
			}
			if (x < map->width - 1)
				ft_printf(" ");
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
