/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_projection_matrix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:54:02 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 12:49:05 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include <math.h>

/**
 * @brief Create a projection matrix for isometric view
 *
 * @return t_mat4 The projection matrix
 */
t_mat4	create_isometric_projection_matrix(void)
{
	return (mat4_isometric());
}

// t_mat4	create_parallel_projection_matrix(t_map_x map_x, t_map_y map_y,
// 	t_elevation elevation)
// {
// 	return (mat4_orthographic(map_x, map_y, elevation));
// }
