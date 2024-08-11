/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:37:04 by welee             #+#    #+#             */
/*   Updated: 2024/08/11 21:51:58 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

static int	get_width(const char *line)
{
	char	**split;
	int		width;

	split = ft_split(line, ' ');
	if (!split)
		return (-1);
	width = 0;
	while (split[width])
	{
		free(split[width]);
		width++;
	}
	free(split);
	return (width);
}

static int	fill_z_matrix(int *z_line, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		z_line[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->z_matrix[i]);
		i++;
	}
	free(map->z_matrix);
	free(map);
}

t_map	*parse_map(const char *filename)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("No file %s\n", filename);
		return (NULL);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Memory allocation failed", errno);
		return (NULL);
	}
	map->height = 0;
	map->width = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		int current_width = get_width(line);
		if (map->width == -1)
			map->width = current_width;
		else if (current_width != map->width)
		{
			free(line);
			free(map);
			close(fd);
			ft_printf("Found wrong line length. Exiting.\n");
			return (NULL);
		}
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0 || map->width == 0)
	{
		free(map);
		ft_printf("No data found. \n");
		return (NULL);
	}
	map->z_matrix = malloc(sizeof(int *) * map->height);
	if (!map->z_matrix)
	{
		free(map);
		ft_printf("Memory allocation failed");
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width);
		if (!map->z_matrix[i] || !fill_z_matrix(map->z_matrix[i], line))
		{
			ft_printf("Map width: %d, height: %d\n", map->width, map->height);
			free(line);
			free_map(map);  // Free the entire map including allocated matrix
			close(fd);
			ft_printf("Error: Failed to parse z_matrix");
			return (NULL);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
