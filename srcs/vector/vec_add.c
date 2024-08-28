/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:36:42 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 18:21:36 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2i	vec2i_add(t_vec2i v1, t_vec2i v2)
{
	t_vec2i	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}

t_vec2f	vec2f_add(t_vec2f v1, t_vec2f v2)
{
	t_vec2f	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}

t_vec3f	vec3f_add(t_vec3f v1, t_vec3f v2)
{
	t_vec3f	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v1.y;
	result.z = v1.z + v2.z;
	return (result);
}
