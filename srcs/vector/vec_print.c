/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:56:04 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:17:48 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_printf.h"

/**
 * @brief Prints a 2D integer vector.
 * @param v The vector.
 */
void	vec2i_print(t_vec2i v)
{
	ft_printf("t_vec2i: {x: %d, y: %d}\n", v.x, v.y);
}

/**
 * @brief Prints a 2D float vector.
 * @param v The vector.
 */
void	vec2f_print(t_vec2f v)
{
	ft_printf("t_vec2f: {x: %d, y: %d}\n", v.x, v.y);
}

/**
 * @brief Prints a 3D float vector.
 * @param v The vector.
 */
void	vec3f_print(t_vec3f v)
{
	ft_printf("t_vec3f: (x: %d, y: %d, z: %d)\n", v.x, v.y, v.z);
}
