/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:42:17 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 13:17:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include <math.h>

t_quaternion	quaternion_normalize(t_quaternion q)
{
	float			magnitude;
	t_quaternion	result;

	magnitude = sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
	result.w = q.w / magnitude;
	result.x = q.x / magnitude;
	result.y = q.y / magnitude;
	result.z = q.z / magnitude;
	return (result);
}
