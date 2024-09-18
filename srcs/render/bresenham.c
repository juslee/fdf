/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:38:56 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:46:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"
#include <stdio.h>

/**
 * @brief Initialize Bresenham's algorithm
 * @param b The Bresenham struct
 * @param start The start point of the line
 * @param end The end point of the line
 */
static void	init_bresenham(t_bresenham *b, t_vec2i start, t_vec2i end)
{
	b->dx = abs(end.x - start.x);
	b->dy = abs(end.y - start.y);
	if (start.x < end.x)
		b->sx = 1;
	else
		b->sx = -1;
	if (start.y < end.y)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx - b->dy;
}

/**
 * @brief Get the factor of a point on a line
 * @param start The start point of the line
 * @param end The end point of the line
 * @param p The point
 * @return float The factor
 */
static float	get_factor(t_pixel start, t_pixel end, t_vec2i p)
{
	float	total_distance;
	float	current_distance;

	total_distance = vec2i_distance(start.point, end.point);
	current_distance = vec2i_distance(start.point, p);
	return (current_distance / total_distance);
}

/**
 * @brief Draw a line using Bresenham's algorithm
 * @param buf The buffer
 * @param start The start point of the line
 * @param end The end point of the line
 */
void	bresenham_line(t_buffer *buf, t_pixel start, t_pixel end)
{
	t_bresenham	b;
	t_vec2i		p;
	int			err2;

	init_bresenham(&b, start.point, end.point);
	p = start.point;
	while (p.x != end.point.x || p.y != end.point.y)
	{
		put_pixel(buf, p,
			lerp_color(start.color, end.color, get_factor(start, end, p)), 1.0);
		err2 = 2 * b.err;
		if (err2 > -b.dy)
		{
			b.err -= b.dy;
			p.x += b.sx;
		}
		if (err2 < b.dx)
		{
			b.err += b.dx;
			p.y += b.sy;
		}
	}
	put_pixel(buf, end.point, end.color, 1.0);
}
