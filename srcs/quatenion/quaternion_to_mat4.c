/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_to_mat4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:43:48 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 12:44:04 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_mat4	quaternion_to_mat4(t_quaternion q)
{
	t_mat4	mat;

	mat = mat4_identity();
	mat.m[0][0] = 1 - 2 * (q.y * q.y + q.z * q.z);
	mat.m[0][1] = 2 * (q.x * q.y - q.z * q.w);
	mat.m[0][2] = 2 * (q.x * q.z + q.y * q.w);
	mat.m[1][0] = 2 * (q.x * q.y + q.z * q.w);
	mat.m[1][1] = 1 - 2 * (q.x * q.x + q.z * q.z);
	mat.m[1][2] = 2 * (q.y * q.z - q.x * q.w);
	mat.m[2][0] = 2 * (q.x * q.z - q.y * q.w);
	mat.m[2][1] = 2 * (q.y * q.z + q.x * q.w);
	mat.m[2][2] = 1 - 2 * (q.x * q.x + q.y * q.y);
	return (mat);
}
