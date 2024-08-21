/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:53:14 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:36:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heightmap.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->z_matrix)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->z_matrix[i]);
			i++;
		}
		free(map->z_matrix);
	}
	free_map_point(map);
	free(map);
}

void	free_map_point(t_map *map)
{
	int	y;

	if (!map || !map->map_points)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->map_points[y]);
		y++;
	}
	free(map->map_points);
	map->map_points = NULL;
}
