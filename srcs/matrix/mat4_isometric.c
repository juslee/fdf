/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_isometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:54:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 18:01:15 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

t_mat4	mat4_isometric(void)
{
	t_mat4	rotate_x;
	t_mat4	rotate_y;
	t_mat4	isometric;

	rotate_y = mat4_rotate_y(M_PI / 4);  // Rotate 45 degrees around the Y-axis
	rotate_x = mat4_rotate_x(atan(1 / sqrt(2)));  // Rotate ~35.264 degrees around the X-axis
	isometric = mat4_multiply(rotate_x, rotate_y);
	return (isometric);
}
