/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_orthographic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:33:42 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 19:14:56 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

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
	result.m[3][3] = 1.0f;
	return (result);
}
