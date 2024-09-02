/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:45:35 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 11:17:08 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Linearly interpolate between two colors
 *
 * @param c1 The first color
 * @param c2 The second color
 * @param t The interpolation factor
 * @return t_color The interpolated color
 */
t_color	lerp_color(t_color c1, t_color c2, float t)
{
	t_color	result;

	result.r = (int)(c1.r + t * (c2.r - c1.r));
	result.g = (int)(c1.g + t * (c2.g - c1.g));
	result.b = (int)(c1.b + t * (c2.b - c1.b));
	result.a = (int)(c1.a + t * (c2.a - c1.a));
	if (result.r > 255)
		result.r = 255;
	if (result.g > 255)
		result.g = 255;
	if (result.b > 255)
		result.b = 255;
	if (result.a > 255)
		result.a = 255;
	return (result);
}
