/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:55:33 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:04:59 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

int	dot_product2d(t_point2d p1, t_point2d p2)
{
	return (p1.x * p2.x + p1.y * p2.y);
}

int	dot_product3d(t_point3d p1, t_point3d p2)
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}

