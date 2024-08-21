/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:37:04 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:26:50 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heightmap.h"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

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
	return (free(split), width);
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
	return (free(split), 1);
}

static int	parse_lines(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width);
		if (!map->z_matrix[i] || !fill_z_matrix(map->z_matrix[i], line))
		{
			free(line);
			while (i > 0)
			{
				i--;
				free(map->z_matrix[i]);
			}
			return (0);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	return (1);
}

static t_map_point	parse_map_point(char *token, int x, int y)
{
	t_map_point	point;
	char		*comma_pos;
	char		*z_str;
	char		*color_str;

	point.point = create_point3d(x, y, 0);
	point.color = create_color(255, 255, 255);
	comma_pos = ft_strchr(token, ',');
	if (comma_pos != NULL)
	{
		*comma_pos = '\0';
		z_str = token;
		color_str = comma_pos + 1;
		point.point.z = ft_atoi(z_str);
		point.color = parse_color(color_str);
	}
	else
	{
		point.point.z = ft_atoi(token);
	}
	return (point);
}

static int	fill_map_points(t_map_point *map_row, char *line, int y)
{
	char	**tokens;
	int		x;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	x = 0;
	while (tokens[x] != NULL)
	{
		map_row[x] = parse_map_point(tokens[x], x, y);
		free(tokens[x]);
		x++;
	}
	return (free(tokens), 1);
}

static int	parse_lines_2(t_map *map, int fd)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	ft_printf("line: %s\n", line);
	while (line != NULL)
	{
		map->map_points[y] = malloc(sizeof(t_map_point) * map->width);
		if (!map->map_points[y] || !fill_map_points(map->map_points[y], line, y))
		{
			free(line);
			while (y > 0)
			{
				y--;
				free(map->map_points[y]);
			}
			free(map->map_points);
			return (0);
		}
		free(line);
		y++;
		line = get_next_line(fd);
	}
	return (1);
}

static int	handle_line(t_map *map, int fd)
{
	char	*line;
	int		current_width;

	map->height = 0;
	map->width = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		current_width = get_width(line);
		if (map->width == -1)
			map->width = current_width;
		else if (current_width != map->width)
			return (free(line), 0);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	parse_map(const char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("No file %s\n", filename), 0);
	if (!handle_line(map, fd))
		return (ft_printf("Found wrong line length. Exiting.\n"), close(fd), 0);
	close(fd);
	if (map->height == 0 || map->width == 0)
		return (ft_printf("No data found.\n"), 0);
	map->z_matrix = malloc(sizeof(int *) * map->height);
	map->map_points = malloc(sizeof(t_map_point *) * map->height);
	if (!map->z_matrix)
		return (ft_printf("Memory allocation failed\n"), 0);
	if (!map->map_points)
		return (ft_printf("Memory allocation failed\n"), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !parse_lines(map, fd))
		return (ft_printf("Error: Failed to parse z_matrix\n"), close(fd), 0);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !parse_lines_2(map, fd))
		return (ft_printf("Error: Failed to parse map_point\n"), close(fd), 0);
	return (close(fd), 1);
}
