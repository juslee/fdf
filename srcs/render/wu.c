/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:48:15 by welee             #+#    #+#             */
/*   Updated: 2024/08/29 14:00:25 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"
#include "vector.h"
#include "render.h"
#include <math.h>

double	ft_frac_part(double x)
{
	return (x - floor(x));
}

double	ft_rfrac_part(double x)
{
	return (1 - ft_frac_part(x));
}

void	ft_handle_endpoint(t_buffer *img, t_vec2i p, t_wu vars, t_color color)
{
	t_vec2i p1, p2;

	p1.x = (int)p.x;
	p1.y = (int)vars.end;
	put_pixel(img, p1, color, ft_rfrac_part(vars.end) * vars.gap);

	p2.x = (int)p.x;
	p2.y = (int)vars.end + 1;
	put_pixel(img, p2, color, ft_frac_part(vars.end) * vars.gap);
}

void	ft_draw_line_shallow(t_buffer *img, t_vec2i start, t_vec2i end, t_wu *vars, t_color color)
{
	int x = start.x + 1;

	while (x < end.x)
	{
		t_vec2i p1 = {x, (int)vars->inter};
		t_vec2i p2 = {x, (int)vars->inter + 1};

		put_pixel(img, p1, color, ft_rfrac_part(vars->inter));
		put_pixel(img, p2, color, ft_frac_part(vars->inter));

		vars->inter += vars->gradient;
		x++;
	}
}

void	ft_wu_shallow(t_buffer *img, t_vec2i start, t_vec2i end, t_color color)
{
	t_wu	vars;

	vars.gradient = (double)(end.y - start.y) / (end.x - start.x);
	vars.end = round(start.x);
	vars.inter = start.y + vars.gradient * (vars.end - start.x);
	vars.gap = ft_rfrac_part(start.x + 0.5);
	ft_handle_endpoint(img, start, vars, color);
	vars.inter += vars.gradient;
	vars.end = round(end.x);
	vars.gap = ft_frac_part(end.x + 0.5);
	ft_handle_endpoint(img, end, vars, color);
	ft_draw_line_shallow(img, start, end, &vars, color);
}

void	ft_draw_line_steep(t_buffer *img, t_vec2i start, t_vec2i end, t_wu *vars, t_color color)
{
	int y = start.y + 1;

	while (y < end.y)
	{
		t_vec2i p1 = {(int)vars->inter, y};
		t_vec2i p2 = {(int)vars->inter + 1, y};

		put_pixel(img, p1, color, ft_rfrac_part(vars->inter));
		put_pixel(img, p2, color, ft_frac_part(vars->inter));

		vars->inter += vars->gradient;
		y++;
	}
}

void	ft_wu_steep(t_buffer *img, t_vec2i start, t_vec2i end, t_color color)
{
	t_wu vars;

	vars.gradient = (double)(end.x - start.x) / (end.y - start.y);
	vars.end = round(start.y);
	vars.inter = start.x + vars.gradient * (vars.end - start.y);
	vars.gap = ft_rfrac_part(start.y + 0.5);
	ft_handle_endpoint(img, start, vars, color);
	vars.inter += vars.gradient;
	vars.end = round(end.y);
	vars.gap = ft_frac_part(end.y + 0.5);
	ft_handle_endpoint(img, end, vars, color);
	ft_draw_line_steep(img, start, end, &vars, color);
}

void	wu_line(t_buffer *img, t_vec2i start, t_vec2i end, t_color color)
{
	t_vec2i	tmp;

	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (start.x > end.x)
		{
			tmp = start;
			start = end;
			end = tmp;
		}
		ft_wu_shallow(img, start, end, color);
	}
	else
	{
		if (start.y > end.y)
		{
			tmp = start;
			start = end;
			end = tmp;
		}
		ft_wu_steep(img, start, end, color);
	}
}
