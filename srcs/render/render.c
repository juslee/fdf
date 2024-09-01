/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:45 by welee             #+#    #+#             */
/*   Updated: 2024/09/01 14:23:54 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"
#include "transform.h"
#include "render.h"
#include "mlx.h"
#include <math.h>

static void	clear_image(t_buffer *buf, int width, int height)
{
	t_vec2i	p;
	t_color	color;

	color = create_color_rgb(0, 0, 0);
	p.y = -1;
	while (p.y++ < height)
	{
		p.x = -1;
		while (p.x++ < width)
		{
			put_pixel(buf, p, color, 1.0);
		}
	}
}

#include <stdio.h>

void	draw_map(t_buffer *buf, t_map *map, t_fdf *fdf)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			t_vec3f point = map->vertex[y][x].position;
			point = mat4_apply_to_vec3(mat4_multiply(fdf->view, fdf->model), point);
			// point = mat4_apply_to_vec3(
			// 		mat4_multiply(
			// 			mat4_rotate_x(M_PI / 6),
			// 			mat4_rotate_z(M_PI / 4)),
			// 		point);
			t_pixel start = { { (int)round(point.x + fdf->offset_x), (int)round(point.y + fdf->offset_y) }, 1.0, map->vertex[y][x].color };
			if (x + 1 < map->width)
			{
				t_vec3f point_next = map->vertex[y][x+1].position;
				point_next = mat4_apply_to_vec3(mat4_multiply(fdf->view, fdf->model), point_next);
				// point_next = mat4_apply_to_vec3(
				// 		mat4_multiply(
				// 			mat4_rotate_x(M_PI / 6),
				// 			mat4_rotate_z(M_PI / 4)),
				// 		point_next);
				t_pixel end = { { (int)round(point_next.x + fdf->offset_x), (int)round(point_next.y + fdf->offset_y) }, 1.0, map->vertex[y][x+1].color };
				bresenham_line(buf, start, end);
			}
			if (y + 1 < map->height)
			{
				t_vec3f point_next = map->vertex[y+1][x].position;
				point_next = mat4_apply_to_vec3(mat4_multiply(fdf->view, fdf->model), point_next);
				// point_next = mat4_apply_to_vec3(
				// 		mat4_multiply(
				// 			mat4_rotate_x(M_PI / 6),
				// 			mat4_rotate_z(M_PI / 4)),
				// 		point_next);
				t_pixel end = { { (int)round(point_next.x + fdf->offset_x), (int)round(point_next.y + fdf->offset_y) }, 1.0, map->vertex[y+1][x].color };
				bresenham_line(buf, start, end);
			}
			x++;
		}
		y++;
	}
}

void	draw_map_vertex(t_buffer *buf, t_vertex vertex[2],
	t_mat4 mvp_matrix, t_fdf *fdf)
{
	t_vec3f	position1;
	t_vec3f	position2;
	t_pixel	start;
	t_pixel	end;

	position1 = vertex[0].position;
	position2 = vertex[1].position;
	position1 = mat4_apply_to_vec3(mvp_matrix, position1);
	position2 = mat4_apply_to_vec3(mvp_matrix, position2);

	start.point = (t_vec2i){(int)round(position1.x) + fdf->offset_x,
		(int)round(position1.y)+ fdf->offset_y};
	start.color = vertex[0].color;
	start.brightness = 1.0;
	end.point = (t_vec2i){(int)round(position2.x)+ fdf->offset_x,
		(int)round(position2.y) + fdf->offset_y};
	end.color = vertex[1].color;
	end.brightness = 1.0;
	bresenham_line(buf, start, end);
}

void	draw_triangle(t_buffer *buf, t_vertex vertex[3], t_mat4 mvp_matrix, t_fdf *fdf)
{
	t_vec3f	pos[3];
	t_pixel	start;
	t_pixel	mid;
	t_pixel	end;

	pos[0] = mat4_apply_to_vec3(mvp_matrix, vertex[0].position);
	pos[1] = mat4_apply_to_vec3(mvp_matrix, vertex[1].position);
	pos[2] = mat4_apply_to_vec3(mvp_matrix, vertex[2].position);
	start = (t_pixel){{(int)round(pos[0].x + fdf->offset_x),
		(int)round(pos[1].y + fdf->offset_y)}, 1.0, vertex[0].color};
	mid = (t_pixel){{(int)round(pos[1].x + fdf->offset_x),
		(int)round(pos[1].y + fdf->offset_y)}, 1.0, vertex[1].color};
	end = (t_pixel){{(int)round(pos[2].x + fdf->offset_x),
		(int)round(pos[2].y + fdf->offset_y)}, 1.0, vertex[2].color};
	bresenham_line(buf, start, mid);
	bresenham_line(buf, mid, end);
	bresenham_line(buf, end, start);
}

int	render(t_fdf *fdf)
{
	t_mat4		mvp_matrix;
	t_vertex	vertex[2];
	int			y;
	int			x;

	// draw_map(&fdf->buffer, fdf->map, fdf);
	mvp_matrix = mat4_multiply(fdf->projection, mat4_multiply(fdf->view, fdf->model));
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			vertex[0] = fdf->map->vertex[y][x];
			if (x + 1 < fdf->map->width)
			{
				vertex[1] = fdf->map->vertex[y][x + 1];
				draw_map_vertex(&fdf->buffer, vertex, mvp_matrix, fdf);
			}
			if (y + 1 < fdf->map->height)
			{
				vertex[1] = fdf->map->vertex[y + 1][x];
				draw_map_vertex(&fdf->buffer, vertex, mvp_matrix, fdf);
			}
		}
	}
	return (0);
}

int	main_loop(t_fdf *fdf)
{
	clear_image(&fdf->buffer, fdf->width, fdf->height);
	render(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->buffer.img, 0, 0);
	return (0);
}
