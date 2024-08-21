/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:31:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:36:26 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEIGHTMAP_H
# define HEIGHTMAP_H

# include "color.h"
# include "point.h"

typedef struct s_map_point
{
	t_point3d	point;
	t_color		color;
}	t_map_point;

typedef struct s_map
{
	int			width;
	int			height;
	int			**z_matrix;
	t_map_point	**map_points;
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
