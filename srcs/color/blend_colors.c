/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:41:46 by welee             #+#    #+#             */
/*   Updated: 2024/08/22 14:42:21 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	blend_colors(t_color c1, t_color c2)
{
	t_color	result;
	float	alpha1;
	float	alpha2;

	alpha1 = c1.a / 255.0f;
	alpha2 = c2.a / 255.0f;
	result.r = (int)((c1.r * alpha1) + (c2.r * (1 - alpha1)));
	result.g = (int)((c1.g * alpha1) + (c2.g * (1 - alpha1)));
	result.b = (int)((c1.b * alpha1) + (c2.b * (1 - alpha1)));
	result.a = 255;
	return (result);
}
