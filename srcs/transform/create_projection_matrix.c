/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_projection_matrix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:54:02 by welee             #+#    #+#             */
/*   Updated: 2024/09/01 14:17:03 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include <math.h>

t_mat4	create_isometric_projection_matrix(t_map_x map_x, t_map_y map_y,
	t_elevation elevation)
{
	t_mat4	ortho_matrix;
	t_mat4	rotate_x;
	t_mat4	rotate_z;
	t_mat4	iso_matrix;

	// ortho_matrix = mat4_orthographic(map_x, map_y, elevation);
	rotate_z = mat4_rotate_z(30 * M_PI / 180);
	rotate_x = mat4_rotate_x(30 * M_PI / 180);
	iso_matrix = mat4_multiply(rotate_z, rotate_x);
	// iso_matrix = mat4_multiply(ortho_matrix, iso_matrix);
	return (iso_matrix);
}

t_mat4	create_parallel_projection_matrix(t_map_x map_x, t_map_y map_y,
	t_elevation elevation)
{
	return (mat4_orthographic(map_x, map_y, elevation));
}
