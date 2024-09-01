/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_perspective.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:39:00 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 15:48:49 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_mat4	mat4_perspective(float fov, float aspect, float near, float far)
{
	t_mat4	perspective;
	float	tan_half_fov;

	tan_half_fov = tan(fov / 2.0f);
	perspective = mat4_identity();
	perspective.m[0][0] = 1.0f / (aspect * tan_half_fov);
	perspective.m[1][1] = 1.0f / tan_half_fov;
	perspective.m[2][2] = -(far + near) / (far - near);
	perspective.m[2][3] = -1.0f;
	perspective.m[3][2] = -(2.0f * far * near) / (far - near);
	perspective.m[3][3] = 0.0f;
	return (perspective);
}
