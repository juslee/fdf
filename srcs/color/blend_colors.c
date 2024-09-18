/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:41:46 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 15:11:22 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Blend two colors
 * @param c1 The first color
 * @param c2 The second color
 * @return t_color The blended color
 */
t_color	blend_colors(t_color c1, t_color c2)
{
	t_color	result;
	float	a1;
	float	a2;
	float	out_alpha;

	a1 = c1.a / 255.0f;
	a2 = c2.a / 255.0f;
	out_alpha = a1 + a2 * (1 - a1);
	if (out_alpha > 0)
	{
		result.r = (int)((c1.r * a1 + c2.r * a2 * (1 - a1)) / out_alpha);
		result.g = (int)((c1.g * a1 + c2.g * a2 * (1 - a1)) / out_alpha);
		result.b = (int)((c1.b * a1 + c2.b * a2 * (1 - a1)) / out_alpha);
		result.a = (int)(out_alpha * 255.0f);
	}
	else
	{
		result.r = 0;
		result.g = 0;
		result.b = 0;
		result.a = 0;
	}
	return (result);
}
