/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:36:18 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:03:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point2d	create_point2d(int x, int y)
{
	t_point2d	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_point3d	create_point3d(int x, int y, int z)
{
	t_point3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
