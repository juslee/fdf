/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_lookat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:55:26 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:54:38 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/**
 * @brief Create a lookat matrix
 * @param eye The eye position
 * @param center The center position
 * @param up The up vector
 * @return t_mat4 The lookat matrix
 */
t_mat4	mat4_lookat(t_vec3f eye, t_vec3f center, t_vec3f up)
{
	t_vec3f	f;
	t_vec3f	r;
	t_vec3f	u;
	t_mat4	lookat;

	f = vec3f_normalize(vec3f_subtract(center, eye));
	r = vec3f_normalize(vec3f_cross(up, f));
	u = vec3f_cross(f, r);
	lookat = mat4_identity();
	lookat.m[0][0] = r.x;
	lookat.m[0][1] = u.x;
	lookat.m[0][2] = -f.x;
	lookat.m[1][0] = r.y;
	lookat.m[1][1] = u.y;
	lookat.m[1][2] = -f.y;
	lookat.m[2][0] = r.z;
	lookat.m[2][1] = u.z;
	lookat.m[2][2] = -f.z;
	lookat.m[3][0] = -vec3f_dot(r, eye);
	lookat.m[3][1] = -vec3f_dot(u, eye);
	lookat.m[3][2] = vec3f_dot(f, eye);
	return (lookat);
}
