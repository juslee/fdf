/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:12:28 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:37:29 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	init_min_max(float *min_max)
{
	min_max[0] = 3.402823e+38;
	min_max[1] = -3.402823e+38;
	min_max[2] = 3.402823e+38;
	min_max[3] = -3.402823e+38;
}

static void	update_min_max(float *min_max, t_vec3f transformed)
{
	if (transformed.x < min_max[0])
		min_max[0] = transformed.x;
	if (transformed.x > min_max[1])
		min_max[1] = transformed.x;
	if (transformed.y < min_max[2])
		min_max[2] = transformed.y;
	if (transformed.y > min_max[3])
		min_max[3] = transformed.y;
}

static void	set_zoom(t_fdf *fdf, float *min_max)
{
	float	width;
	float	height;
	float	zoom_x;
	float	zoom_y;

	width = min_max[1] - min_max[0];
	height = min_max[3] - min_max[2];
	zoom_x = (fdf->win_width - fdf->image_width - 2 * fdf->padding) / width;
	zoom_y = (fdf->win_height - 2 * fdf->padding) / height;
	fdf->zoom = fmin(zoom_x, zoom_y);
}

static void	set_offset(t_fdf *fdf, float *min_max)
{
	float	width;
	float	height;

	width = min_max[1] - min_max[0];
	height = min_max[3] - min_max[2];
	fdf->offset_x = (fdf->win_width - fdf->image_width - width * fdf->zoom) / 2
		- min_max[0] * fdf->zoom;
	fdf->offset_y = (fdf->win_height - height * fdf->zoom) / 2
		- min_max[2] * fdf->zoom;
}

void	set_zoom_offset(t_fdf *fdf)
{
	int			x;
	int			y;
	t_vec3f		vector;
	t_vec3f		transformed;
	float		min_max[4];

	init_min_max(min_max);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			vector = fdf->map->vertices[y][x].pos;
			transformed = mat4_multiply_vec3(fdf->mvp, vector);
			update_min_max(min_max, transformed);
			x++;
		}
		y++;
	}
	set_zoom(fdf, min_max);
	set_offset(fdf, min_max);
}
