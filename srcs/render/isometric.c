/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:09:42 by welee             #+#    #+#             */
/*   Updated: 2024/08/15 15:13:11 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point	isometric_projection(int x, int y, int z)
{
	t_point	result;
	double	angle;

	angle = M_PI / 60;
	result.x = (x - y) * cos(angle);
	result.y = (x + y) * sin(angle) - z;
	return (result);
}
