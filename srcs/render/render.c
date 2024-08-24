/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:45 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 18:09:16 by welee            ###   ########.fr       */
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

void	draw_map(t_image *img, t_map *map)
{
	t_point	start;
	t_point	end;
	int		y;
	int		x;
	int		z;
	int		next_z;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			z = map->z_matrix[y][x];
			start = isometric_projection(x, y, z);
			if (x + 1 < map->width)
			{
				next_z = map->z_matrix[y][x + 1];
				end = isometric_projection((x + 1), y, next_z);
				bresenham_line(img, start, end, 0xFFFFFF);
			}
			if (y + 1 < map->height)
			{
				next_z = map->z_matrix[y + 1][x];
				end = isometric_projection(x, (y + 1), next_z);
				bresenham_line(img, start, end, 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
}

int	render(t_fdf *fdf)
{
	draw_map(&fdf->image, fdf->map);
	return (0);
}

void	swap_buffers(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.img, 0, 0);
}

int main_loop(t_fdf *fdf)
{
	clear_image(&fdf->image, fdf->width, fdf->height);
	render(fdf);
	swap_buffers(fdf);
	return (0);
}
