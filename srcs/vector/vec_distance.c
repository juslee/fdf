/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:52:12 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:16:51 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

/**
 * @brief Calculates the distance between two 2D integer vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The distance between the two vectors.
 */
float	vec2i_distance(t_vec2i v1, t_vec2i v2)
{
	int	dx;
	int	dy;

	dx = v1.x - v2.x;
	dy = v1.y - v2.y;
	return (sqrt(dx * dx + dy * dy));
}

/**
 * @brief Calculates the distance between two 2D float vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The distance between the two vectors.
 */
float	vec2f_distance(t_vec2f v1, t_vec2f v2)
{
	int	dx;
	int	dy;

	dx = v1.x - v2.x;
	dy = v1.y - v2.y;
	return (sqrtf(dx * dx + dy * dy));
}

/**
 * @brief Calculates the distance between two 3D float vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The distance between the two vectors.
 */
float	vec3f_distance(t_vec3f v1, t_vec3f v2)
{
	int	dx;
	int	dy;
	int	dz;

	dx = v2.x - v1.x;
	dy = v2.y - v1.y;
	dz = v2.z - v1.z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}
