/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_brightness.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:44:45 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 11:22:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Adjust the brightness of a color
 *
 * @param color The color
 * @param factor The brightness factor
 * @return t_color The adjusted color
 */
t_color	adjust_brightness(t_color color, float factor)
{
	t_color	result;

	result.r = (int)(color.r * factor);
	result.g = (int)(color.g * factor);
	result.b = (int)(color.b * factor);
	result.a = color.a;
	if (result.r > 255)
		result.r = 255;
	if (result.g > 255)
		result.g = 255;
	if (result.b > 255)
		result.b = 255;
	if (result.r < 0)
		result.r = 0;
	if (result.g < 0)
		result.g = 0;
	if (result.b < 0)
		result.b = 0;
	return (result);
}
