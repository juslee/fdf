/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:55:07 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:05:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point2d	scale_point2d(t_point2d p, int scalar)
{
	t_point2d	result;

	result.x = p.x * scalar;
	result.y = p.y * scalar;
	return (result);
}

t_point3d	scale_point3d(t_point3d p, int scalar)
{
	t_point3d	result;

	result.x = p.x * scalar;
	result.y = p.y * scalar;
	result.z = p.z * scalar;
	return (result);
}
