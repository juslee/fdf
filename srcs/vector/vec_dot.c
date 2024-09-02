/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:55:33 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 09:39:29 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec2i_dot(t_vec2i v1, t_vec2i v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float	vec2f_dot(t_vec2f v1, t_vec2f v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float	vec3f_dot(t_vec3f v1, t_vec3f v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
