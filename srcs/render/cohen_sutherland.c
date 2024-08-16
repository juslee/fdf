/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:59:37 by welee             #+#    #+#             */
/*   Updated: 2024/08/17 00:18:48 by welee            ###   ########.fr       */
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

static int	compute_region_code(t_point p)
{
	int	code;

	code = INSIDE;
	if (p.x < X_MIN)
		code |= LEFT;
	else if (p.x > X_MAX)
		code |= RIGHT;
	if (p.y < Y_MIN)
		code |= BOTTOM;
	else if (p.y > Y_MAX)
		code |= TOP;
	return (code);
}

static t_point	get_intersection(t_point s, t_point e, int code_out)
{
	t_point	new_point;

	new_point.x = 0;
	new_point.y = 0;
	if (code_out & TOP)
	{
		new_point.x = s.x + (e.x - s.x) * (Y_MAX - s.y) / (e.y - s.y);
		new_point.y = Y_MAX;
	}
	else if (code_out & BOTTOM)
	{
		new_point.x = s.x + (e.x - s.x) * (Y_MIN - s.y) / (e.y - s.y);
		new_point.y = Y_MIN;
	}
	else if (code_out & RIGHT)
	{
		new_point.y = s.y + (e.y - s.y) * (X_MAX - s.x) / (e.x - s.x);
		new_point.x = X_MAX;
	}
	else if (code_out & LEFT)
	{
		new_point.y = s.y + (e.y - s.y) * (X_MIN - s.x) / (e.x - s.x);
		new_point.x = X_MIN;
	}
	return (new_point);
}

static void	update_point(t_point *start, t_point *end, int *code, int code_out)
{
	t_point	new_point;

	new_point = get_intersection(*start, *end, code_out);
	*start = new_point;
	*code = compute_region_code(*start);
}

int	cohen_sutherland_clip(t_point *start, t_point *end)
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

