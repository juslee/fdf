/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:35:14 by welee             #+#    #+#             */
/*   Updated: 2024/08/10 16:08:50 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_matrix;
}	t_map;

/*
** Function Prototypes
*/
void	free_map(t_map *map);

#endif
