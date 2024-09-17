/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:17:52 by welee             #+#    #+#             */
/*   Updated: 2024/09/16 00:56:21 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map.h"
#include "ft_printf.h"
#include <stdio.h>

void	print_map(t_map *map)
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
			ft_printf("%d", (int)map->vertices[y][x].pos.z);
			if (!is_default_color(map->vertices[y][x].color))
			{
				hex_color = color_to_hex(map->vertices[y][x].color);
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
