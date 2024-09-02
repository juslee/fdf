/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:24:38 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 12:49:41 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

/**
 * @brief Create a translation
 *
 * @param tx The translation x
 * @param ty The translation y
 * @param tz The translation z
 * @return t_translation The translation
 */
t_translation	create_translation(float tx, float ty, float tz)
{
	t_translation	translation;

	translation.tx = tx;
	translation.ty = ty;
	translation.tz = tz;
	return (translation);
}

/**
 * @brief Create a scaling
 *
 * @param sx The scaling x
 * @param sy The scaling y
 * @param sz The scaling z
 * @return t_scaling The scaling
 */
t_scaling	create_scaling(float sx, float sy, float sz)
{
	t_scaling	scaling;

	scaling.sx = sx;
	scaling.sy = sy;
	scaling.sz = sz;
	return (scaling);
}

/**
 * @brief Create a rotation
 *
 * @param angle_x The angle x
 * @param angle_y The angle y
 * @param angle_z The angle z
 * @return t_rotation The rotation
 */
t_rotation	create_rotation(float angle_x, float angle_y, float angle_z)
{
	t_rotation	rotation;

	rotation.angle_x = angle_x;
	rotation.angle_y = angle_y;
	rotation.angle_z = angle_z;
	return (rotation);
}

/**
 * @brief Create a model matrix
 *
 * @param translation The translation
 * @param rotation The rotation
 * @param scaling The scaling
 * @return t_mat4 The model matrix
 */
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
