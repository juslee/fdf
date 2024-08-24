/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:22:39 by welee             #+#    #+#             */
/*   Updated: 2024/08/22 15:23:22 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

t_vec2	vec2_create(float x, float y);
t_vec2	vec2_add(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2);
t_vec2	vec2_scale(t_vec2 v, int scalar);
float	vec2_dot(t_vec2 v1, t_vec2 v2);
float	vec2_length(t_vec2 v);
t_vec2	vec2_normalize(t_vec2 v);
float	vec2_distance(t_vec2 v1, t_vec2 v2);
void	vec2_print(t_vec2 v);

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

t_vec3	vec3_create(float x, float y, float z);
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_scale(t_vec3 v, int scalar);
float	vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);
float	vec3_length(t_vec3 v);
t_vec3	vec3_normalize(t_vec3 v);
float	vec3_distance(t_vec3 v1, t_vec3 v2);
void	vec3_print(t_vec3 v);

#endif
