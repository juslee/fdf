/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:14:56 by welee             #+#    #+#             */
/*   Updated: 2024/09/16 12:11:18 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(t_map *map)
{
	int	y;

	if (!map || !map->vertices)
		return ;
	y = 0;
	while (y < map->height)
	{
		if (map->vertices[y])
			free(map->vertices[y]);
		y++;
	}
	free(map->vertices);
	map->vertices = NULL;
}

void	free_fdf(t_fdf *fdf)
{
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->buffer.img)
		mlx_destroy_image(fdf->mlx_ptr, fdf->buffer.img);
	if (fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->mlx_ptr)
	{
		mlx_loop_end(fdf->mlx_ptr);
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
}
