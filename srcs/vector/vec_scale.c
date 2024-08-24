/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:55:07 by welee             #+#    #+#             */
/*   Updated: 2024/08/22 12:53:50 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec2_scale(t_vec2 v, int scalar)
{
	t_vec2	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	return (result);
}

t_vec3	vec3_scale(t_vec3 v, int scalar)
{
	t_vec3	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}
