/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:35:36 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 15:11:35 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Create color with rgba value
 * @param r The red value
 * @param g The green value
 * @param b The blue value
 * @param a The alpha value
 * @return t_color The color
 */
t_color	create_color_rgba(int r, int g, int b, int a)
{
	t_color	color;

	if (r >= 0 && r <= 255)
		color.r = r;
	else
		color.r = 255;
	if (g >= 0 && g <= 255)
		color.g = g;
	else
		color.g = 255;
	if (b >= 0 && b <= 255)
		color.b = b;
	else
		color.b = 255;
	if (a >= 0 && a <= 255)
		color.a = a;
	else
		color.a = 255;
	return (color);
}

/**
 * @brief Create color with rgb value
 *
 * @param r The red value
 * @param g The green value
 * @param b The blue value
 * @return t_color The color
 */
t_color	create_color_rgb(int r, int g, int b)
{
	t_color	color;

	color = create_color_rgba(r, g, b, 255);
	return (color);
}
