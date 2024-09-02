/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:38:59 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 13:46:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "quaternion.h"
#include <math.h>

/**
 * @brief Update the rotation z of the transform matrix
 *
 * @param transform pointer to the transform matrix
 * @param angle the angle to be rotated
 */
void	update_rotation_z(t_mat4 *transform, float angle)
{
	t_mat4	mat_rotation;

	mat_rotation = mat4_rotate_z(angle);
	*transform = mat4_multiply(*transform, mat_rotation);
}

/**
 * @brief Update the rotation y of the transform matrix
 *
 * @param transform pointer to the transform matrix
 * @param angle the angle to be rotated
 */
void	update_rotation_y(t_mat4 *transform, float angle)
{
	t_mat4	mat_rotation;

	mat_rotation = mat4_rotate_y(angle);
	*transform = mat4_multiply(*transform, mat_rotation);
}

/**
 * @brief Update the rotation x of the transform matrix
 *
 * @param transform pointer to the transform matrix
 * @param angle the angle to be rotated
 */
void	update_rotation_x(t_mat4 *transform, float angle)
{
	t_mat4	mat_rotation;

	mat_rotation = mat4_rotate_x(angle);
	*transform = mat4_multiply(*transform, mat_rotation);
}

/**
 * @brief Update the rotation of the transform matrix
 *
 * @param transform pointer to the transform matrix
 * @param rotation the rotation to be applied
 * @return void
 */
void	update_rotation(t_mat4 *transform, t_rotation rotation)
{
	t_mat4	mat_rotation;

	// rotation.angle_x = fmax(fmin(rotation.angle_x, MAX_ANGLE_X), MIN_ANGLE_X);
	// rotation.angle_y = fmax(fmin(rotation.angle_y, MAX_ANGLE_Y), MIN_ANGLE_Y);
	// rotation.angle_z = fmax(fmin(rotation.angle_z, MAX_ANGLE_Z), MIN_ANGLE_Z);
	mat_rotation = mat4_rotate(rotation);
	*transform = mat4_multiply(*transform, mat_rotation);
	mat4_print(*transform);
}
