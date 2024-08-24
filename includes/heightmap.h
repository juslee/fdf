/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:31:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 17:46:48 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEIGHTMAP_H
# define HEIGHTMAP_H

# include "color.h"
# include "vector.h"

typedef struct s_vertex
{
	t_vec3	position;
	// t_vec2	projection; // Not used
	t_color	color;
}	t_vertex;

typedef struct s_map
{
	int			width;
	int			height;
	int			**z_matrix;
	t_vertex	**vertex;
}	t_map;

/*
** Function Prototypes
*/
int		parse_map(const char *filename, t_map *map);
void	free_map(t_map *map);
void	free_map_point(t_map *map);

// Debugging Prototypes
void	print_map(t_map *map);
void	print_map_point(t_map *map);

#endif
