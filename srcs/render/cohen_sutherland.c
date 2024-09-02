/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:59:37 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 11:01:24 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define INSIDE 0
#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

#define X_MIN 0
#define Y_MIN 0
#define X_MAX WIN_WIDTH
#define Y_MAX WIN_HEIGHT

static int	compute_region_code(t_vec2i p)
{
	int	code;

	code = INSIDE;
	if (p.x < X_MIN)
		code |= LEFT;
	else if (p.x > X_MAX - 1)
		code |= RIGHT;
	if (p.y < Y_MIN)
		code |= BOTTOM;
	else if (p.y > Y_MAX - 1)
		code |= TOP;
	return (code);
}

static t_vec2i	get_intersection(t_vec2i s, t_vec2i e, int code_out)
{
	t_vec2i	new_point;

	new_point.x = 0;
	new_point.y = 0;
	if (code_out & TOP)
	{
		new_point.x = s.x + (e.x - s.x) * (Y_MAX - 1 - s.y) / (e.y - s.y);
		new_point.y = Y_MAX - 1;
	}
	else if (code_out & BOTTOM)
	{
		new_point.x = s.x + (e.x - s.x) * (Y_MIN - s.y) / (e.y - s.y);
		new_point.y = Y_MIN;
	}
	else if (code_out & RIGHT)
	{
		new_point.y = s.y + (e.y - s.y) * (X_MAX - 1 - s.x) / (e.x - s.x);
		new_point.x = X_MAX - 1;
	}
	else if (code_out & LEFT)
	{
		new_point.y = s.y + (e.y - s.y) * (X_MIN - s.x) / (e.x - s.x);
		new_point.x = X_MIN;
	}
	return (new_point);
}

static void	update_point(t_vec2i *start, t_vec2i *end, int *code, int code_out)
{
	t_vec2i	new_point;

	new_point = get_intersection(*start, *end, code_out);
	*start = new_point;
	*code = compute_region_code(*start);
}

int	cohen_sutherland_clip(t_vec2i *start, t_vec2i *end)
{
	int	code1;
	int	code2;

	code1 = compute_region_code(*start);
	code2 = compute_region_code(*end);
	while (code1 != 0 || code2 != 0)
	{
		if (code1 & code2)
			return (0);
		if (code1 != 0)
			update_point(start, end, &code1, code1);
		else
			update_point(end, start, &code2, code2);
	}
	return (1);
}
