/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:50:22 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 13:23:35 by welee            ###   ########.fr       */
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

// t_mat4	mat4_rotate(t_rotation angle)
// {
// 	t_quaternion	q_x;
// 	t_quaternion	q_y;
// 	t_quaternion	q_z;
// 	t_quaternion	q_combined;
// 	t_mat4			rotation_matrix;

// 	// Convert Euler angles to quaternions for each axis
// 	q_x = euler_to_quaternion(angle.angle_x, 0, 0);
// 	q_y = euler_to_quaternion(0, angle.angle_y, 0);
// 	q_z = euler_to_quaternion(0, 0, angle.angle_z);

// 	// Combine the quaternions by multiplying them
// 	q_combined = quaternion_multiply(q_z, quaternion_multiply(q_y, q_x));

// 	// Normalize the resulting quaternion to ensure it represents a valid rotation
// 	q_combined = quaternion_normalize(q_combined);

// 	// Convert the final quaternion to a rotation matrix
// 	rotation_matrix = quaternion_to_mat4(q_combined);

// 	return (rotation_matrix);
// }
