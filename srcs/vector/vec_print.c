/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:56:04 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 18:25:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_printf.h"

void	vec2i_print(t_vec2i v)
{
	ft_printf("t_vec2i: {x: %d, y: %d}\n", v.x, v.y);
}

void	vec2f_print(t_vec2f v)
{
	ft_printf("t_vec2f: {x: %d, y: %d}\n", v.x, v.y);
}

void	vec3f_print(t_vec3f v)
{
	ft_printf("t_vec3f: (x: %d, y: %d, z: %d)\n", v.x, v.y, v.z);
}
