/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_default_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:12:28 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 11:19:45 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Check if the color is default color
 *
 * @param color The color
 * @return int 1 if the color is default color, 0 otherwise
 */
int	is_default_color(t_color color)
{
	if (color.r == 255 && color.g == 255 && color.b == 255)
		return (1);
	return (0);
}
