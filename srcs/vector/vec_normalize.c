/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:34:28 by welee             #+#    #+#             */
/*   Updated: 2024/08/22 13:50:43 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec2	vec2_normalize(t_vec2 v)
{
	t_vec2	result;
	float	length;

	length = sqrt(v.x * v.x + v.y * v.y);
	if (length == 0)
		return (v);
	result.x = v.x / length;
	result.y = v.y / length;
	return (result);
}

t_vec3	vec3_normalize(t_vec3 v)
{
	t_vec3	result;
	float	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (length == 0)
		return (v);
	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;
	return (result);
}
