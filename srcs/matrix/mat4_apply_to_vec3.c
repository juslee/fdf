/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_apply_to_vec3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:55:36 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 17:43:19 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_vec3	mat4_apply_to_vec3(t_mat4 mat, t_vec3 vec)
{
	t_vec3	result;
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
