/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 01:27:53 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:54:56 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/**
 * @brief Create a model matrix
 * @param scaling The scaling factor
 * @param rotation The rotation factor
 * @param translation The translation factor
 * @return t_mat4 The model matrix
 */
t_mat4	mat4_model(t_scaling scaling, t_rotation rotation,
	t_translation translation)
{
	t_mat4	scale;
	t_mat4	rotate;
	t_mat4	translate;
	t_mat4	model;

	scale = mat4_scale(scaling);
	rotate = mat4_rotate(rotation);
	translate = mat4_translate(translation);
	model = mat4_multiply(rotate, scale);
	model = mat4_multiply(translate, model);
	return (model);
}
