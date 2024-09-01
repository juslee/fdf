/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_to_quaternion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:31:19 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 13:16:49 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include <math.h>

t_quaternion	euler_to_quaternion(float angle_x, float angle_y, float angle_z)
{
	t_quaternion	q;
	float			s[3];
	float			c[3];

	c[0] = cos(angle_x * 0.5f);
	s[0] = sin(angle_x * 0.5f);
	c[1] = cos(angle_y * 0.5f);
	s[1] = sin(angle_y * 0.5f);
	c[2] = cos(angle_z * 0.5f);
	s[2] = sin(angle_z * 0.5f);
	q.w = c[0] * c[1] * c[2] + s[0] * s[1] * s[2];
	q.x = s[0] * c[1] * c[2] - c[0] * s[1] * s[2];
	q.y = c[0] * s[1] * c[2] + s[0] * c[1] * s[2];
	q.z = c[0] * c[1] * s[2] - s[0] * s[1] * c[2];
	return (q);
}
