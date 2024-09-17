/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:31:52 by welee             #+#    #+#             */
/*   Updated: 2024/09/16 00:56:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "color.h"
# include "vector.h"

# define DEFAULT_COLOR "0xFFFFFF"

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
	t_vec3f	pos;
	t_color	color;
}	t_vertex;

typedef struct s_map
{
	int			width;
	int			height;
	int			max_elev;
	int			min_elev;
	t_vertex	**vertices;
}	t_map;

/*
** Function Prototypes
*/
int		parse_map(char *filename, t_map *map);

// Debugging Prototypes
void	print_map(t_map *map);

#endif
