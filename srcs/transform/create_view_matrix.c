/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_view_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:46:57 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 12:48:55 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"
#include "matrix.h"

/**
 * @brief Create a view matrix
 *
 * @param translation The translation
 * @param rotation The rotation
 * @param scaling The scaling
 * @return t_mat4 The view matrix
 */
t_mat4	create_view_matrix(t_translation translation,
	t_rotation rotation, t_scaling scaling)
{
	t_mat4	view_matrix;
	t_mat4	translate_matrix;
	t_mat4	scale_matrix;
	t_mat4	rotate_matrix;

	translate_matrix = mat4_translate(translation);
	rotate_matrix = mat4_rotate(rotation);
	scale_matrix = mat4_scale(scaling);
	view_matrix = mat4_multiply(translate_matrix,
			mat4_multiply(rotate_matrix, scale_matrix));
	return (view_matrix);
}

// t_mat4	create_view_matrix(t_vec3f eye, t_vec3f center, t_vec3f up)
// {
// 	return (mat4_lookat(eye, center, up));
// }
