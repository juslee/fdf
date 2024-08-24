/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:56:04 by welee             #+#    #+#             */
/*   Updated: 2024/08/22 13:33:32 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_printf.h"

void	vec2_print(t_vec2 v)
{
	ft_printf("t_vec2: {x: %d, y: %d}\n", v.x, v.y);
}

void	vec3_print(t_vec3 v)
{
	ft_printf("t_vec3: (x: %d, y: %d, z: %d)\n", v.x, v.y, v.z);
}
