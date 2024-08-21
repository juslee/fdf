/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:42:21 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 15:42:57 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	hex_to_color(int hex_value)
{
	t_color	color;

	color.r = (hex_value >> 16) & 0xFF;
	color.g = (hex_value >> 8) & 0xFF;
	color.b = hex_value & 0xFF;
	return (color);
}
