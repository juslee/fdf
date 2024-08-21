/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:37:05 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:06:11 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point2d	subtract_points2d(t_point2d p1, t_point2d p2)
{
	t_point2d	point;

	point.x = p1.x - p2.x;
	point.y = p1.y - p2.y;
	return (point);
}

t_point3d	subtract_points3d(t_point3d p1, t_point3d p2)
{
	t_point3d	result;

	result.x = p1.x - p2.x;
	result.y = p1.y - p2.y;
	result.z = p1.z - p2.z;
	return (result);
}
