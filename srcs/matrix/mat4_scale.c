/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:49:41 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 16:33:58 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	mat4_scale(t_scale scale)
{
	t_mat4	mat;

	mat = mat4_identity();
	mat.m[0][0] = scale.sx;
	mat.m[1][1] = scale.sy;
	mat.m[2][2] = scale.sz;
	return (mat);
}
