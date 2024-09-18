/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:55:33 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:17:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * @brief Calculates the dot product of two 2D integer vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The dot product of the two vectors.
 */
int	vec2i_dot(t_vec2i v1, t_vec2i v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

/**
 * @brief Calculates the dot product of two 2D float vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The dot product of the two vectors.
 */
float	vec2f_dot(t_vec2f v1, t_vec2f v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

/**
 * @brief Calculates the dot product of two 3D float vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The dot product of the two vectors.
 */
float	vec3f_dot(t_vec3f v1, t_vec3f v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
