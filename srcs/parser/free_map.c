/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:53:14 by welee             #+#    #+#             */
/*   Updated: 2024/08/13 10:59:38 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	free(map);
}
