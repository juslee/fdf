/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_points2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:36:42 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:03:21 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point2d	add_points2d(t_point2d p1, t_point2d p2)
{
	t_point2d	point;

	point.x = p1.x + p2.x;
	point.y = p1.y + p2.y;
	return (point);
}

t_point3d	add_points3d(t_point3d p1, t_point3d p2)
{
	t_point3d	point;

	point.x = p1.x + p2.x;
	point.y = p1.y + p2.y;
	point.z = p1.z + p2.z;
	return (point);
}
