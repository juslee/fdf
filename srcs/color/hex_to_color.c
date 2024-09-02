/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:42:21 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 11:18:54 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Convert hex value to color
 *
 * @param hex_value The hex value
 * @return t_color The color
*/
t_color	hex_to_color(int hex_value)
{
	t_color	color;

	color.r = (hex_value >> 16) & 0xFF;
	color.g = (hex_value >> 8) & 0xFF;
	color.b = hex_value & 0xFF;
	color.a = 255;
	return (color);
}
