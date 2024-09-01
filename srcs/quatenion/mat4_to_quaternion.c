/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_to_quaternion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:44:50 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 13:17:09 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include <math.h>

static void	compute_quaternion_from_trace(t_mat4 mat, t_quaternion *q)
{
	float	s;

	s = 0.5f / sqrtf(mat.m[0][0] + mat.m[1][1] + mat.m[2][2] + 1.0f);
	q->w = 0.25f / s;
	q->x = (mat.m[2][1] - mat.m[1][2]) * s;
	q->y = (mat.m[0][2] - mat.m[2][0]) * s;
	q->z = (mat.m[1][0] - mat.m[0][1]) * s;
}

static void	compute_quaternion_x(t_mat4 mat, t_quaternion *q)
{
	float	s;

	s = 2.0f * sqrtf(1.0f + mat.m[0][0] - mat.m[1][1] - mat.m[2][2]);
	q->w = (mat.m[2][1] - mat.m[1][2]) / s;
	q->x = 0.25f * s;
	q->y = (mat.m[0][1] + mat.m[1][0]) / s;
	q->z = (mat.m[0][2] + mat.m[2][0]) / s;
}

static void	compute_quaternion_y(t_mat4 mat, t_quaternion *q)
{
	float	s;

	s = 2.0f * sqrtf(1.0f + mat.m[1][1] - mat.m[0][0] - mat.m[2][2]);
	q->w = (mat.m[0][2] - mat.m[2][0]) / s;
	q->x = (mat.m[0][1] + mat.m[1][0]) / s;
	q->y = 0.25f * s;
	q->z = (mat.m[1][2] + mat.m[2][1]) / s;
}

static void	compute_quaternion_z(t_mat4 mat, t_quaternion *q)
{
	float	s;

	s = 2.0f * sqrtf(1.0f + mat.m[2][2] - mat.m[0][0] - mat.m[1][1]);
	q->w = (mat.m[1][0] - mat.m[0][1]) / s;
	q->x = (mat.m[0][2] + mat.m[2][0]) / s;
	q->y = (mat.m[1][2] + mat.m[2][1]) / s;
	q->z = 0.25f * s;
}

t_quaternion	mat4_to_quaternion(t_mat4 mat)
{
	t_quaternion	q;

	if (mat.m[0][0] + mat.m[1][1] + mat.m[2][2] > 0)
		compute_quaternion_from_trace(mat, &q);
	else if (mat.m[0][0] > mat.m[1][1] && mat.m[0][0] > mat.m[2][2])
		compute_quaternion_x(mat, &q);
	else if (mat.m[1][1] > mat.m[2][2])
		compute_quaternion_y(mat, &q);
	else
		compute_quaternion_z(mat, &q);
	return (q);
}
