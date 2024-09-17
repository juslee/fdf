/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:49:41 by welee             #+#    #+#             */
/*   Updated: 2024/09/17 08:39:18 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/**
 * @brief Create a scaling matrix
 *
 * @param scale The scaling
 * @return t_mat4 The scaling matrix
 */
t_mat4	mat4_scale(t_scaling scaling)
{
	t_mat4	mat;

	mat = mat4_identity();
	mat.m[0][0] = scaling.sx;
	mat.m[1][1] = scaling.sy;
	mat.m[2][2] = scaling.sz;
	return (mat);
}
