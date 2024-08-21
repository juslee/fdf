/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_between_points2d.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:52:12 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:04:23 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include <math.h>

float	distance_between_points2d(t_point2d p1, t_point2d p2)
{
	int	dx;
	int	dy;

	dx = p1.x - p2.x;
	dy = p1.y - p2.y;
	return (sqrtf(dx * dx + dy * dy));
}

float	distance_between_points3d(t_point3d p1, t_point3d p2)
{
	int	dx;
	int	dy;
	int	dz;

	dx = p1.x - p2.x;
	dy = p1.y - p2.y;
	dz = p1.z - p2.z;
	return (sqrtf(dx * dx + dy * dy + dz * dz));
}
