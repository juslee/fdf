/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:55:07 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:18:03 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * @brief Scales a 2D integer vector by a scalar.
 * @param v The vector.
 * @param scalar The scalar.
 * @return The scaled vector.
 */
t_vec2i	vec2i_scale(t_vec2i v, int scalar)
{
	t_vec2i	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	return (result);
}

/**
 * @brief Scales a 2D float vector by a scalar.
 * @param v The vector.
 * @param scalar The scalar.
 * @return The scaled vector.
 */
t_vec2f	vec2f_scale(t_vec2f v, int scalar)
{
	t_vec2f	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	return (result);
}

/**
 * @brief Scales a 3D float vector by a scalar.
 * @param v The vector.
 * @param scalar The scalar.
 * @return The scaled vector.
 */
t_vec3f	vec3f_scale(t_vec3f v, int scalar)
{
	t_vec3f	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}
