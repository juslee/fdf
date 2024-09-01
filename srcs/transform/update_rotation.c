/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:38:59 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 14:04:18 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "quaternion.h"
#include <math.h>

void	update_rotation_z(t_mat4 *transform, float angle)
{
	t_mat4	mat_rotation;

	mat_rotation = mat4_rotate_z(angle);
	*transform = mat4_multiply(*transform, mat_rotation);
}

void	update_rotation_y(t_mat4 *transform, float angle)
{
	t_mat4	mat_rotation;

	mat_rotation = mat4_rotate_y(angle);
	*transform = mat4_multiply(*transform, mat_rotation);
}

void	update_rotation_x(t_mat4 *transform, float angle)
{
	t_mat4	mat_rotation;

	mat_rotation = mat4_rotate_x(angle);
	*transform = mat4_multiply(*transform, mat_rotation);
}

void	update_rotation(t_mat4 *transform, t_rotation rotation)
{
	t_mat4	mat_rotation;

	mat_rotation = mat4_rotate(rotation);
	*transform = mat4_multiply(*transform, mat_rotation);
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
