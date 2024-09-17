/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_orthographic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:33:42 by welee             #+#    #+#             */
/*   Updated: 2024/09/17 14:25:02 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/**
 * @brief Create an orthographic matrix
 *
 * @param map_x The x-axis map
 * @param map_y The y-axis map
 * @param elevation The elevation map
 * @return t_mat4 The orthographic matrix
 */
t_mat4	mat4_orthographic(t_map_x map_x, t_map_y map_y, t_elevation elevation)
{
	t_mat4	result;

	result = mat4_identity();
	result.m[0][0] = 2.0f / (map_x.right - map_x.left);
	result.m[1][1] = 2.0f / (map_y.top - map_y.bottom);
	result.m[2][2] = -2.0f / (elevation.far - elevation.near);
	result.m[0][3] = -(map_x.right + map_x.left) / (map_x.right - map_x.left);
	result.m[1][3] = -(map_y.top + map_y.bottom) / (map_y.top - map_y.bottom);
	result.m[2][3] = -(elevation.far + elevation.near) / (
			elevation.far - elevation.near);
	return (result);
}
