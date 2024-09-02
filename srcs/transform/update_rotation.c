/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:38:59 by welee             #+#    #+#             */
/*   Updated: 2024/09/01 17:07:44 by welee            ###   ########.fr       */
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
