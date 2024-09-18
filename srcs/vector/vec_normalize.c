/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:34:28 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:17:37 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

/**
 * @brief Normalizes a 2D integer vector.
 * @param v The vector.
 * @return The normalized vector.
 */
t_vec2i	vec2i_normalize(t_vec2i v)
{
	t_vec2i	result;
	float	length;

	length = sqrtf(v.x * v.x + v.y * v.y);
	if (length == 0)
		return (v);
	result.x = v.x / length;
	result.y = v.y / length;
	return (result);
}

/**
 * @brief Normalizes a 2D float vector.
 * @param v The vector.
 * @return The normalized vector.
 */
t_vec2f	vec2f_normalize(t_vec2f v)
{
	t_vec2f	result;
	float	length;

	length = sqrt(v.x * v.x + v.y * v.y);
	if (length == 0)
		return (v);
	result.x = v.x / length;
	result.y = v.y / length;
	return (result);
}

/**
 * @brief Normalizes a 3D float vector.
 * @param v The vector.
 * @return The normalized vector.
 */
t_vec3f	vec3f_normalize(t_vec3f v)
{
	t_vec3f	result;
	float	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (length == 0)
		return (v);
	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return (result);
}
