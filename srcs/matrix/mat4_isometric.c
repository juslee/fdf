/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_isometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:54:52 by welee             #+#    #+#             */
/*   Updated: 2024/09/17 18:59:36 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

/**
 * @brief Create an isometric matrix
 *
 * @return t_mat4 The isometric matrix
 */
t_mat4	mat4_isometric(void)
{
	t_mat4	rotate_x;
	t_mat4	rotate_y;
	t_mat4	isometric;

	rotate_x = mat4_rotate_x(atan(1 / sqrt(2)));
	rotate_y = mat4_rotate_y(-45 * M_PI / 180);
	isometric = mat4_multiply(rotate_x, rotate_y);
	return (isometric);
}
