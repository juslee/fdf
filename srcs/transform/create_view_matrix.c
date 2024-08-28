/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_view_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:46:57 by welee             #+#    #+#             */
/*   Updated: 2024/08/27 17:44:37 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

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
