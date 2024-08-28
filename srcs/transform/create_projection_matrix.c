/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_projection_matrix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:54:02 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 19:14:08 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include <math.h>

t_mat4	create_isometric_projection_matrix(t_map_x map_x, t_map_y map_y,
	t_elevation elevation)
{
	t_mat4	ortho_matrix;
	t_mat4	rotate_x;
	t_mat4	rotate_y;
	t_mat4	iso_matrix;

	ortho_matrix = mat4_orthographic(map_x, map_y, elevation);
	rotate_y = mat4_rotate_y(M_PI / 4);
	rotate_x = mat4_rotate_x(M_PI / 6);
	iso_matrix = mat4_multiply(rotate_x, rotate_y);
	iso_matrix = mat4_multiply(ortho_matrix, iso_matrix);
	return (iso_matrix);
}

t_mat4	create_parallel_projection_matrix(t_map_x map_x, t_map_y map_y,
	t_elevation elevation)
{
	return (mat4_orthographic(map_x, map_y, elevation));
}
