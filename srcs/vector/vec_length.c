/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:03:49 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:17:24 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

/**
 * @brief Calculates the length of a 2D integer vector.
 * @param v The vector.
 * @return The length of the vector.
 */
float	vec2i_length(t_vec2i v)
{
	return (sqrtf(v.x * v.x + v.y * v.y));
}

/**
 * @brief Calculates the length of a 2D float vector.
 * @param v The vector.
 * @return The length of the vector.
 */
float	vec2f_length(t_vec2f v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

/**
 * @brief Calculates the length of a 3D float vector.
 * @param v The vector.
 * @return The length of the vector.
 */
float	vec3f_length(t_vec3f v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
