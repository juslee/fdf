/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:24:38 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 18:40:57 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_translation	create_translation(float tx, float ty, float tz)
{
	t_translation	translation;

	translation.tx = tx;
	translation.ty = ty;
	translation.tz = tz;

	return (translation);
}

t_scale	create_scale(float sx, float sy, float sz)
{
	t_scale	scale;

	scale.sx = sx;
	scale.sy = sy;
	scale.sz = sz;

	return (scale);
}

t_rotation	create_rotation(float angle_x, float angle_y, float angle_z)
{
	t_rotation	rotation;

	rotation.angle_x = angle_x;
	rotation.angle_y = angle_y;
	rotation.angle_z = angle_z;
}

t_mat4	create_transform(t_translation translation, t_scale scale,
	t_rotation rotation)
{
	t_mat4	mat_translation;
	t_mat4	mat_scaling;
	t_mat4	mat_rotation;
	t_mat4	combined_transform;

	mat_translation = mat4_translate(translation);
	mat_scaling = mat4_scale(scale);
	mat_rotation = mat4_rotate(rotation);
	combined_transform = mat4_multiply(mat_translation, mat_scaling);
	combined_transform = mat4_multiply(combined_transform, mat_rotation);
	return (combined_transform);
}
