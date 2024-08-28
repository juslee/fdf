/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:38:56 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 18:57:14 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

static float	get_t(t_pixel start, t_pixel end, t_vec2i p)
{
	float	total_distance;
	float	current_distance;

	total_distance = vec2i_distance(start.point, end.point);
	current_distance = vec2i_distance(start.point, p);
	return (current_distance / total_distance);
}

void	bresenham_line(t_buffer *buf, t_pixel start, t_pixel end)
{
	t_bresenham	b;
	t_vec2i		p;
	int			err2;

	if (!cohen_sutherland_clip(&start.point, &end.point))
		return ;
	init_bresenham(&b, start.point, end.point);
	p = start.point;
	while (p.x != end.point.x || p.y != end.point.y)
	{
		put_pixel(buf, p,
			lerp_color(start.color, end.color, get_t(start, end, p)), 1.0);
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
