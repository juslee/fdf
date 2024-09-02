/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:48:44 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 12:59:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/**
 * @brief Create a translation matrix
 *
 * @param translation The translation
 * @return t_mat4 The translation matrix
 */
t_mat4	mat4_translate(t_translation translation)
{
	t_mat4	mat;

	mat = mat4_identity();
	mat.m[0][3] = translation.tx;
	mat.m[1][3] = translation.ty;
	mat.m[2][3] = translation.tz;
	return (mat);
}
