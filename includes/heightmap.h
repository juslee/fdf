/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:31:52 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 11:25:15 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEIGHTMAP_H
# define HEIGHTMAP_H

# include "color.h"
# include "vector.h"

// vertex is the 3D point in the world
//     Z
//     |
//     |
//     |
//     +-------- X
//    /
//   /
//  /
// Y
typedef struct s_vertex
{
	t_vec3f	position;
	t_color	color;
}	t_vertex;

//
typedef struct s_map
{
	int			width;
	int			height;
	int			max_elevation;
	int			min_elevation;
	t_vertex	**vertex;
}	t_map;

/*
** Function Prototypes
*/
int		parse_map(const char *filename, t_map *map);
// void	free_map(t_map *map);
void	free_map_point(t_map *map);
int		handle_line(t_map *map, int fd);

// Debugging Prototypes
// void	print_map(t_map *map);
// void	print_vertex(t_map *map);

#endif
