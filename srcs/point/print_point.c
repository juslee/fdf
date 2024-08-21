/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:56:04 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 18:10:39 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_point2d.c
 * @brief Function to print 2D point
 */
#include "point.h"
#include "ft_printf.h"

/**
 * @brief Print 2D point
 *
 * @param p 2D point
 */
void	print_point2d(t_point2d p)
{
	ft_printf("Point2D: (x: %d, y: %d)\n", p.x, p.y);
}

/**
 * @brief Print 3D point
 *
 * @param p 3D point
 */
void	print_point3d(t_point3d p)
{
	ft_printf("Point3D: (x: %d, y: %d, z: %d)\n", p.x, p.y, p.z);
}
