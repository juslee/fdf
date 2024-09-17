/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:59:37 by welee             #+#    #+#             */
/*   Updated: 2024/09/17 17:57:44 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"

#define INSIDE 0
#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

static int	compute_region_code(t_vec2i p, t_viewport *viewport)
{
	int	code;

	code = INSIDE;
	if (p.x < viewport->min.x)
		code |= LEFT;
	else if (p.x > viewport->max.x - 1)
		code |= RIGHT;
	if (p.y < viewport->min.y)
		code |= BOTTOM;
	else if (p.y > viewport->max.y - 1)
		code |= TOP;
	return (code);
}

static t_vec2i	compute_intersection(t_vec2i s, t_vec2i e, int code_out,
			t_viewport *v)
{
	t_vec2i	new_point;

	new_point.x = 0;
	new_point.y = 0;
	if (code_out & TOP)
	{
		new_point.x = s.x + (e.x - s.x) * (v->max.y - 1 - s.y) / (e.y - s.y);
		new_point.y = v->max.y - 1;
	}
	else if (code_out & BOTTOM)
	{
		new_point.x = s.x + (e.x - s.x) * (v->min.y - s.y) / (e.y - s.y);
		new_point.y = v->min.y;
	}
	else if (code_out & RIGHT)
	{
		new_point.y = s.y + (e.y - s.y) * (v->max.x - 1 - s.x) / (e.x - s.x);
		new_point.x = v->max.x - 1;
	}
	else if (code_out & LEFT)
	{
		new_point.y = s.y + (e.y - s.y) * (v->min.x - s.x) / (e.x - s.x);
		new_point.x = v->min.x;
	}
	return (new_point);
}

static int	update_point(t_vec2i *start, t_vec2i *end, int code_out,
	t_viewport *viewport)
{
	t_vec2i	new_point;

	new_point = compute_intersection(*start, *end, code_out, viewport);
	*start = new_point;
	return (compute_region_code(*start, viewport));
}

int	cohen_sutherland_clip(t_vec2i *start, t_vec2i *end, t_viewport *viewport)
{
	int	code[2];

	code[0] = compute_region_code(*start, viewport);
	code[1] = compute_region_code(*end, viewport);
	while (code[0] != 0 || code[1] != 0)
	{
		if (code[0] & code[1])
			return (0);
		if (code[0] != 0)
			code[0] = update_point(start, end, code[0], viewport);
		else
			code[1] = update_point(end, start, code[1], viewport);
	}
	return (1);
}
