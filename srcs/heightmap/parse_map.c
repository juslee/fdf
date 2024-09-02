/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:37:04 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 09:46:59 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heightmap.h"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

// static int	get_min_max_elevation(char *line, int *min_elevation,
// int *max_elevation)
// {
// 	char	**tokens;
// 	int		i;
// 	int		elevation;
// 	char	*comma_pos;

// 	tokens = ft_split(line, ' ');
// 	if (!tokens)
// 		return (0);
// 	i = 0;
// 	while (tokens[i] != NULL)
// 	{
// 		comma_pos = ft_strchr(tokens[i], ',');
// 		if (comma_pos != NULL)
// 			*comma_pos = '\0'; // Remove the color part
// 		elevation = ft_atoi(tokens[i]);
// 		if (elevation < *min_elevation)
// 			*min_elevation = elevation;
// 		if (elevation > *max_elevation)
// 			*max_elevation = elevation;
// 		free(tokens[i]);
// 		i++;
// 	}
// 	free(tokens);
// 	return (1);
// }

// static int	fill_z_matrix(int *z_line, char *line)
// {
// 	char	**split;
// 	int		i;

// 	split = ft_split(line, ' ');
// 	if (!split)
// 		return (0);
// 	i = 0;
// 	while (split[i])
// 	{
// 		z_line[i] = ft_atoi(split[i]);
// 		free(split[i]);
// 		i++;
// 	}
// 	return (free(split), 1);
// }

// static int	parse_lines(t_map *map, int fd)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		map->z_matrix[i] = malloc(sizeof(int) * map->width);
// 		if (!map->z_matrix[i] || !fill_z_matrix(map->z_matrix[i], line))
// 		{
// 			free(line);
// 			while (i > 0)
// 			{
// 				i--;
// 				free(map->z_matrix[i]);
// 			}
// 			return (0);
// 		}
// 		free(line);
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	return (1);
// }

static t_vertex	parse_vertex(char *token, int x, int y)
{
	t_vertex	point;
	char		*comma_pos;
	char		*z_str;
	char		*color_str;
	char		*newline_pos;

	point.position = vec3f_create(x, y, 0);
	point.color = create_color_rgb(255, 255, 255);
	comma_pos = ft_strchr(token, ',');
	if (comma_pos != NULL)
	{
		*comma_pos = '\0';
		z_str = token;
		color_str = comma_pos + 1;
		newline_pos = ft_strchr(color_str, '\n');
		if (newline_pos)
			*newline_pos = '\0';
		point.position.z = ft_atoi(z_str);
		point.color = parse_color(color_str);
	}
	else
		point.position.z = ft_atoi(token);
	return (point);
}

static int	fill_vertex(t_vertex *map_row, char *line, int y)
{
	char	**tokens;
	int		x;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	x = 0;
	while (tokens[x] != NULL)
	{
		map_row[x] = parse_vertex(tokens[x], x, y);
		free(tokens[x]);
		x++;
	}
	return (free(tokens), 1);
}

static int	parse_lines(t_map *map, int fd)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->vertex[y] = malloc(sizeof(t_vertex) * map->width);
		if (!map->vertex[y] || !fill_vertex(map->vertex[y], line, y))
		{
			free(line);
			while (y > 0)
			{
				y--;
				free(map->vertex[y]);
			}
			free(map->vertex);
			return (0);
		}
		free(line);
		y++;
		line = get_next_line(fd);
	}
	return (1);
}

/**
 * @brief Parse the map file and store the data in the map struct
 *
 * @param filename The name of the file to parse
 * @param map The map struct to store the data
 * @return int 1 if the parsing was successful, 0 otherwise
 */
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
	map->vertex = malloc(sizeof(t_vertex *) * map->height);
	if (!map->vertex)
		return (ft_printf("Memory allocation failed\n"), 0);
	fd = open(filename, O_RDONLY);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || !parse_lines(map, fd))
		return (ft_printf("Error: Failed to parse map_point\n"), close(fd), 0);
	return (close(fd), 1);
}
