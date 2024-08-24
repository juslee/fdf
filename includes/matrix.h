/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:54:07 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 16:40:19 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct s_mat4
{
	float	m[4][4];
}	t_mat4;

typedef struct s_scale
{
	float	sx;
	float	sy;
	float	sz;
}	t_scale;

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

// Function prototypes
t_mat4	mat4_identity(void);
t_mat4	mat4_multiply(t_mat4 a, t_mat4 b);
t_mat4	mat4_translate(t_translation translation);
t_mat4	mat4_scale(t_scale scale);
t_mat4	mat4_rotate_x(float angle);
t_mat4	mat4_rotate_y(float angle);
t_mat4	mat4_rotate_z(float angle);
t_mat4	mat4_rotate(t_rotation angle);
t_vec3	mat4_apply_to_vec3(t_mat4 m, t_vec3 v);

#endif
