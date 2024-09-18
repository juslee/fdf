/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:56:18 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:16:25 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * @brief Calculates the cross product of two 3D float vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The cross product of the two vectors.
 */
t_vec3f	vec3f_cross(t_vec3f v1, t_vec3f v2)
{
	t_vec3f	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}
