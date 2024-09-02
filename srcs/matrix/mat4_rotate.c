/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:50:22 by welee             #+#    #+#             */
/*   Updated: 2024/09/01 17:07:22 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "quaternion.h"
#include <math.h>

t_mat4	mat4_rotate_x(float angle)
{
	t_mat4	mat;
	float	cos_a;
	float	sin_a;

	mat = mat4_identity();
	cos_a = cos(angle);
	sin_a = sin(angle);
	mat.m[1][1] = cos_a;
	mat.m[1][2] = -sin_a;
	mat.m[2][1] = sin_a;
	mat.m[2][2] = cos_a;
	return (mat);
}

t_mat4	mat4_rotate_y(float angle)
{
	t_mat4	mat;
	float	cos_a;
	float	sin_a;

	mat = mat4_identity();
	cos_a = cos(angle);
	sin_a = sin(angle);
	mat.m[0][0] = cos_a;
	mat.m[0][2] = sin_a;
	mat.m[2][0] = -sin_a;
	mat.m[2][2] = cos_a;
	return (mat);
}

t_mat4	mat4_rotate_z(float angle)
{
	t_mat4	mat;
	float	cos_a;
	float	sin_a;

	mat = mat4_identity();
	cos_a = cos(angle);
	sin_a = sin(angle);
	mat.m[0][0] = cos_a;
	mat.m[0][1] = -sin_a;
	mat.m[1][0] = sin_a;
	mat.m[1][1] = cos_a;
	return (mat);
}

t_mat4	mat4_rotate(t_rotation angle)
{
	t_mat4	rotation_x;
	t_mat4	rotation_y;
	t_mat4	rotation_z;
	t_mat4	result;

	rotation_x = mat4_rotate_x(angle.angle_x);
	rotation_y = mat4_rotate_y(angle.angle_y);
	rotation_z = mat4_rotate_z(angle.angle_z);
	result = mat4_multiply(rotation_x, rotation_y);
	result = mat4_multiply(result, rotation_z);
	return (result);
}
