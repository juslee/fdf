/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:54:07 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 17:48:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct s_mat4
{
	float	m[4][4];
}	t_mat4;

typedef struct s_scaling
{
	float	sx;
	float	sy;
	float	sz;
}	t_scaling;

typedef struct s_rotation
{
	float	angle_x;
	float	angle_y;
	float	angle_z;
}	t_rotation;

typedef struct s_translation
{
	float	tx;
	float	ty;
	float	tz;
}	t_translation;

typedef struct s_map_x
{
	float	left;
	float	right;
}	t_map_x;

typedef struct s_map_y
{
	float	bottom;
	float	top;
}	t_map_y;

typedef struct s_elevation
{
	float	near;
	float	far;
}	t_elevation;

// Function prototypes
float	mat4_determinant(t_mat4 mat);
t_mat4	mat4_identity(void);
t_mat4	mat4_multiply(t_mat4 a, t_mat4 b);
t_mat4	mat4_translate(t_translation translation);
t_mat4	mat4_scale(t_scaling scale);
t_mat4	mat4_rotate_x(float angle);
t_mat4	mat4_rotate_y(float angle);
t_mat4	mat4_rotate_z(float angle);
t_mat4	mat4_rotate(t_rotation angle);
t_mat4	mat4_orthographic(t_map_x map_x,
			t_map_y map_y, t_elevation elevation);
t_mat4	mat4_lookat(t_vec3f eye, t_vec3f center, t_vec3f up);
t_mat4	mat4_perspective(float fov, float aspect_ratio,
			float near, float far);
t_mat4	mat4_isometric(void);
t_mat4	mat4_model(t_scaling scaling, t_rotation rotation,
			t_translation translation);
t_vec3f	mat4_multiply_vec3(t_mat4 m, t_vec3f v);

// Debugging
void	mat4_print(t_mat4 m);

#endif
