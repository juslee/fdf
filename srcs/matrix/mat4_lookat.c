/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_lookat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:55:26 by welee             #+#    #+#             */
/*   Updated: 2024/09/01 12:41:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	mat4_lookat(t_vec3f eye, t_vec3f center, t_vec3f up)
{
	t_vec3f	f;  // Forward vector
	t_vec3f	r;  // Right vector
	t_vec3f	u;  // Up vector
	t_mat4	lookat;

	// Calculate forward vector (from camera to target, Y-axis points out of screen)
	f = vec3f_normalize(vec3f_subtract(center, eye));

	// Calculate right vector (X-axis direction)
	r = vec3f_normalize(vec3f_cross(up, f));  // Note: cross(up, forward)

	// Recalculate up vector (Z-axis direction)
	u = vec3f_cross(f, r);

	// Initialize the lookat matrix to identity
	lookat = mat4_identity();

	// Set rotation part
	lookat.m[0][0] = r.x;
	lookat.m[0][1] = u.x;
	lookat.m[0][2] = -f.x;

	lookat.m[1][0] = r.y;
	lookat.m[1][1] = u.y;
	lookat.m[1][2] = -f.y;

	lookat.m[2][0] = r.z;
	lookat.m[2][1] = u.z;
	lookat.m[2][2] = -f.z;

	// Set translation part
	lookat.m[3][0] = -vec3f_dot(r, eye);
	lookat.m[3][1] = -vec3f_dot(u, eye);
	lookat.m[3][2] = vec3f_dot(f, eye);

	return (lookat);
}
