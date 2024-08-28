/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:09:42 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 15:04:00 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point	isometric_projection(int x, int y, int z)
{
	t_point	result;
	double	angle_x;
	double	angle_y;

	angle_y = M_PI / 4;
	angle_x = M_PI / 6;
	result.x = (x - y) * cos(angle_x);
	result.y = (x + y) * sin(angle_y) - z;
	return (result);
}
