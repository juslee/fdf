/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:38:56 by welee             #+#    #+#             */
/*   Updated: 2024/08/15 18:24:31 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	init_bresenham(t_bresenham *b, t_point start, t_point end)
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

void	bresenham_line(t_image *img, t_point start, t_point end, int color)
{
	t_bresenham	b;
	t_point		p;
	int			err2;

	init_bresenham(&b, start, end);
	p = start;
	while (p.x != end.x || p.y != end.y)
	{
		put_pixel(img, p, color, 1.0);
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
	put_pixel(img, end, color, 1.0);
}
