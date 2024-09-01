/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:25:25 by welee             #+#    #+#             */
/*   Updated: 2024/08/29 16:29:00 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "libft.h"
#include <stddef.h>
#include <stdio.h>

t_color	parse_color(const char *color_str)
{
	t_color	color;
	int		hex_value;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	if (color_str && ft_strlen(color_str) == 8
		&& color_str[0] == '0' && color_str[1] == 'x')
	{
		hex_value = (int)ft_strtol(&color_str[2], NULL, 16);
		color = hex_to_color(hex_value);
	}
	return (color);
}
