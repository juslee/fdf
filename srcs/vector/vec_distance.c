/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:52:12 by welee             #+#    #+#             */
/*   Updated: 2024/08/22 13:08:02 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

float	vec2_distance(t_vec2 v1, t_vec2 v2)
{
	int	dx;
	int	dy;

	dx = v1.x - v2.x;
	dy = v1.y - v2.y;
	return (sqrtf(dx * dx + dy * dy));
}

float	vec3_distance(t_vec3 v1, t_vec3 v2)
{
	int	dx;
	int	dy;
	int	dz;

	dx = v2.x - v1.x;
	dy = v2.y - v1.y;
	dz = v2.z - v1.z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}
