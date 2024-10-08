/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:47:40 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 15:11:50 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/**
 * @brief Check if two colors are equal
 * @param c1 The first color
 * @param c2 The second color
 * @return int 1 if equal, 0 otherwise
 */
int	is_equal_color(t_color c1, t_color c2)
{
	if (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)
		return (1);
	return (0);
}
