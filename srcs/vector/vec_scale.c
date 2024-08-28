/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:55:07 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 18:25:17 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2i	vec2i_scale(t_vec2i v, int scalar)
{
	t_vec2i	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	return (result);
}

t_vec2f	vec2f_scale(t_vec2f v, int scalar)
{
	t_vec2f	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	return (result);
}

t_vec3f	vec3f_scale(t_vec3f v, int scalar)
{
	t_vec3f	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}
