/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:14:56 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 16:00:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Free the split string.
 * @param split The split string.
 */
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

/**
 * @brief Free the map.
 * @param map The map structure.
 */
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
	free(map);
}

/**
 * @brief Free the fdf structure.
 * @param fdf The fdf structure.
 */
void	free_fdf(t_fdf *fdf)
{
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->img_ptr)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	if (fdf->buffer.img)
		mlx_destroy_image(fdf->mlx_ptr, fdf->buffer.img);
	if (fdf->win_ptr)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->win_ptr = NULL;
	}
	if (fdf->mlx_ptr)
	{
		mlx_loop_end(fdf->mlx_ptr);
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
		fdf->mlx_ptr = NULL;
	}
}
