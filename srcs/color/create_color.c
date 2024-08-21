/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:35:36 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 15:43:14 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	create_color(int r, int g, int b)
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
	return (color);
}
