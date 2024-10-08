/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_multiply_vec3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:55:36 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:55:08 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/**
 * @brief Multiply a 4x4 matrix by a 3D vector
 *
 * @param mat The matrix
 * @param vec The vector
 * @return t_vec3f The result vector
 */
t_vec3f	mat4_multiply_vec3(t_mat4 mat, t_vec3f vec)
{
	t_vec3f	result;
	float	w;

	result.x = mat.m[0][0] * vec.x + mat.m[0][1] * vec.y + mat.m[0][2] * vec.z
		+ mat.m[0][3];
	result.y = mat.m[1][0] * vec.x + mat.m[1][1] * vec.y + mat.m[1][2] * vec.z
		+ mat.m[1][3];
	result.z = mat.m[2][0] * vec.x + mat.m[2][1] * vec.y + mat.m[2][2] * vec.z
		+ mat.m[2][3];
	w = mat.m[3][0] * vec.x + mat.m[3][1] * vec.y + mat.m[3][2] * vec.z
		+ mat.m[3][3];
	if (w != 1.0f && w != 0.0f)
	{
		result.x /= w;
		result.y /= w;
		result.z /= w;
	}
	return (result);
}
