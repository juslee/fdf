/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:22:39 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 18:42:24 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

t_vec2i	vec2i_create(int x, int y);
t_vec2i	vec2i_add(t_vec2i v1, t_vec2i v2);
t_vec2i	vec2i_subtract(t_vec2i v1, t_vec2i v2);
t_vec2i	vec2i_scale(t_vec2i v, int scalar);
int		vec2i_dot(t_vec2i v1, t_vec2i v2);
float	vec2i_length(t_vec2i v);
t_vec2i	vec2i_normalize(t_vec2i v);
float	vec2i_distance(t_vec2i v1, t_vec2i v2);
void	vec2i_print(t_vec2i v);

typedef struct s_vec2f
{
	float	x;
	float	y;
}	t_vec2f;

t_vec2f	vec2f_create(float x, float y);
t_vec2f	vec2f_add(t_vec2f v1, t_vec2f v2);
t_vec2f	vec2f_subtract(t_vec2f v1, t_vec2f v2);
t_vec2f	vec2f_scale(t_vec2f v, int scalar);
float	vec2f_dot(t_vec2f v1, t_vec2f v2);
float	vec2f_length(t_vec2f v);
t_vec2f	vec2f_normalize(t_vec2f v);
float	vec2f_distance(t_vec2f v1, t_vec2f v2);
void	vec2f_print(t_vec2f v);

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3f;

t_vec3f	vec3f_create(float x, float y, float z);
t_vec3f	vec3f_add(t_vec3f v1, t_vec3f v2);
t_vec3f	vec3f_subtract(t_vec3f v1, t_vec3f v2);
t_vec3f	vec3f_scale(t_vec3f v, int scalar);
float	vec3f_dot(t_vec3f v1, t_vec3f v2);
t_vec3f	vec3f_cross(t_vec3f v1, t_vec3f v2);
float	vec3f_length(t_vec3f v);
t_vec3f	vec3f_normalize(t_vec3f v);
float	vec3f_distance(t_vec3f v1, t_vec3f v2);
void	vec3f_print(t_vec3f v);

#endif
