/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:37:04 by welee             #+#    #+#             */
/*   Updated: 2024/09/19 11:48:41 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map.h"
#include "utils.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * @brief Parse vertex
 * @param point_str The point string
 * @param x The x coordinate
 * @param y The y coordinate
 * @param map The map
 * @return int 1 if success, 0 otherwise
 */
static int	parse_vertex(char *point_str, int x, int y, t_map *map)
{
	char		**split;
	char		*point_trim;

	point_trim = ft_strtrim(point_str, "\n");
	split = ft_split(point_trim, ',');
	if (!split)
		return (free(point_trim), error_map("Memory allocation failed", map));
	map->vertices[y][x].pos = vec3f_create(x, y, ft_atoi(split[0]));
	map->vertices[y][x].color = parse_color(DEFAULT_COLOR);
	if (split[1])
		map->vertices[y][x].color = parse_color(split[1]);
	free_split(split);
	free(point_trim);
	return (1);
}

/**
 * @brief Parse line
 * @param line The line
 * @param y The y coordinate
 * @param map The map
 * @return int 1 if success, 0 otherwise
 */
static int	parse_line(char *line, int y, t_map *map)
{
	char	**split;
	int		x;

	map->vertices[y] = (t_vertex *)malloc(sizeof(t_vertex) * map->width);
	if (!map->vertices[y])
		return (error_map("Memory allocation failed", map));
	split = ft_split(line, ' ');
	if (!split)
		return (error_map("Memory allocation failed", map));
	x = 0;
	while (x < map->width && split[x])
	{
		if (!parse_vertex(split[x], x, y, map))
			return (free_split(split), error_map("Invalid map point", map));
		x++;
	}
	free_split(split);
	return (1);
}

/**
 * @brief Read map
 * @param filename The filename
 * @param map The map
 * @return int 1 if success, 0 otherwise
 */
static int	read_map(char *filename, t_map *map)
{
	char	*line;
	int		y;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_file(filename, map));
	map->vertices = (t_vertex **)malloc(sizeof(t_vertex *) * map->height);
	if (!map->vertices)
		return (close(fd), error_map("Memory allocation failed", map));
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!parse_line(line, y, map))
			return (free(line), free_map(map), 0);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	if (y == 0)
		return (error_map("No data found.", map));
	return (1);
}

/**
 * @brief Get line size
 * @param line The line
 * @param map The map
 * @return int 1 if success, 0 otherwise
 */
static int	get_line_size(char *line, t_map *map)
{
	char	**split;
	int		width;

	split = ft_split(line, ' ');
	if (!split)
		return (error_map("Memory allocation failed", map));
	width = 0;
	while (split[width])
	{
		free(split[width]);
		width++;
	}
	free(split);
	if (map->width != 0 && width != map->width)
		return (error_map("Found wrong line length. Exiting.", map));
	map->width = width;
	return (1);
}

/**
 * @brief Parse map
 * @param filename The filename
 * @param map The map
 * @return int 1 if success, 0 otherwise
 */
int	parse_map(char *filename, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error_file(filename, map));
	map->width = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!get_line_size(line, map))
			return (free(line), close(fd), 0);
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0)
		return (error_map("No data found.", map));
	if (!read_map(filename, map))
		return (0);
	return (1);
}
