/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:24:38 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 19:13:03 by welee            ###   ########.fr       */
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

t_scaling	create_scaling(float sx, float sy, float sz)
{
	t_scaling	scaling;

	scaling.sx = sx;
	scaling.sy = sy;
	scaling.sz = sz;
	return (scaling);
}

t_rotation	create_rotation(float angle_x, float angle_y, float angle_z)
{
	t_rotation	rotation;

	rotation.angle_x = angle_x;
	rotation.angle_y = angle_y;
	rotation.angle_z = angle_z;
	return (rotation);
}

t_mat4	create_model_matrix(t_translation translation, t_rotation rotation,
	t_scaling scaling)
{
	t_mat4	translate_matrix;
	t_mat4	rotate_matrix;
	t_mat4	scale_matrix;
	t_mat4	model_matrix;

	translate_matrix = mat4_translate(translation);
	rotate_matrix = mat4_rotate(rotation);
	scale_matrix = mat4_scale(scaling);
	model_matrix = mat4_multiply(translate_matrix,
			mat4_multiply(rotate_matrix, scale_matrix));
	return (model_matrix);
}
