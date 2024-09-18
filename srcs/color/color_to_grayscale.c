/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_grayscale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:43:01 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 15:11:28 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Convert color to grayscale
 * @param color The color
 * @return t_color The grayscale color
 */
t_color	color_to_grayscale(t_color color)
{
	int		luminance;
	t_color	grayscale;

	luminance = (int)(0.3 * color.r + 0.59 * color.g + 0.11 * color.b);
	grayscale.r = luminance;
	grayscale.g = luminance;
	grayscale.b = luminance;
	grayscale.a = color.a;
	return (grayscale);
}
