/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:48:44 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 16:33:26 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	mat4_translate(t_translation translation)
{
	t_mat4	mat;

	mat = mat4_identity();
	mat.m[0][3] = translation.tx;
	mat.m[1][3] = translation.ty;
	mat.m[2][3] = translation.tz;
	return (mat);
}
