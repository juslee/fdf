/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:40:45 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 15:11:31 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Convert color to hex value
 * @param color The color
 * @return int The hex value
 */
int	color_to_hex(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}
