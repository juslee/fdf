/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:36:18 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 18:22:00 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2i	vec2i_create(int x, int y)
{
	t_vec2i	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vec2f	vec2f_create(float x, float y)
{
	t_vec2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vec3f	vec3f_create(float x, float y, float z)
{
	t_vec3f	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}
