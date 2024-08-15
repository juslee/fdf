/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:45 by welee             #+#    #+#             */
/*   Updated: 2024/08/15 20:16:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

static void	clear_image(t_image *img, int width, int height)
{
	t_point	p;
	int		color;

	color = 0x000000;
	p.y = -1;
	while (p.y++ < height)
	{
		p.x = -1;
		while (p.x++ < width)
		{
			put_pixel(img, p, color, 1.0);
		}
	}
}

static t_point	isometric_projection(int x, int y, int z)
{
	t_point	result;
	double	angle;

	angle = M_PI / 6;
	result.x = (x - y) * cos(angle);
	result.y = (x + y) * sin(angle) - z;
	return (result);
}
#include <stdio.h>

void	draw_map(t_image *img, t_map *map, int scale)
{
	t_point	start;
	t_point	end;

	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			printf("x: %d, y: %d\n", x, y);
			int z = map->z_matrix[y][x];
			printf("z: %d\n", z);
			start = isometric_projection(x * scale, y * scale, z * scale);
			printf("start.x: %d, start.y: %d\n", start.x, start.y);
			if (x + 1 < map->width)
			{
				int next_z = map->z_matrix[y][x + 1];
				printf("next_z x + 1 < map->width: %d\n", next_z);
				end = isometric_projection((x + 1) * scale, y * scale, next_z * scale);
				bresenham_line(img, start, end, 0xFFFFFF);
			}
			if (y + 1 < map->height)
			{
				int next_z = map->z_matrix[y + 1][x];
				printf("next_z y + 1 < map->height: %d\n", next_z);
				end = isometric_projection(x * scale, (y + 1) * scale, next_z * scale);
				bresenham_line(img, start, end, 0xFFFFFF);
			}
		}
	}
}

int	render(t_fdf *fdf)
{
	t_image	*current_img;

	if (fdf->current_img == 0)
		current_img = &fdf->img1;
	else
		current_img = &fdf->img2;
	clear_image(current_img, fdf->width, fdf->height);
	draw_map(current_img, fdf->map, fdf->zoom);
	mlx_put_image_to_window(fdf->mlx, fdf->win, current_img->img, 0, 0);
	fdf->current_img = 1 - fdf->current_img;
	return (0);
}
