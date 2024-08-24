/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:53:14 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 18:10:49 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heightmap.h"
#include <stdlib.h>

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

	if (!map || !map->vertex)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->vertex[y]);
		y++;
	}
	free(map->vertex);
	map->vertex = NULL;
}
