/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:45 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 19:31:53 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"
#include "transform.h"
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
			point = mat4_apply_to_vec3(
					mat4_multiply(
						mat4_rotate_x(M_PI / 6),
						mat4_rotate_z(M_PI / 4)),
					point);
			t_pixel start = { { (int)round(point.x + fdf->offset_x), (int)round(point.y + fdf->offset_y) }, 1.0, map->vertex[y][x].color };
			if (x + 1 < map->width)
			{
				t_vec3f point_next = map->vertex[y][x+1].position;
				point_next = mat4_apply_to_vec3(mat4_multiply(fdf->view, fdf->model), point_next);
				point_next = mat4_apply_to_vec3(
						mat4_multiply(
							mat4_rotate_x(M_PI / 6),
							mat4_rotate_z(M_PI / 4)),
						point_next);
				t_pixel end = { { (int)round(point_next.x + fdf->offset_x), (int)round(point_next.y + fdf->offset_y) }, 1.0, map->vertex[y][x+1].color };
				bresenham_line(buf, start, end);
			}
			if (y + 1 < map->height)
			{
				t_vec3f point_next = map->vertex[y+1][x].position;
				point_next = mat4_apply_to_vec3(mat4_multiply(fdf->view, fdf->model), point_next);
				point_next = mat4_apply_to_vec3(
						mat4_multiply(
							mat4_rotate_x(M_PI / 6),
							mat4_rotate_z(M_PI / 4)),
						point_next);
				t_pixel end = { { (int)round(point_next.x + fdf->offset_x), (int)round(point_next.y + fdf->offset_y) }, 1.0, map->vertex[y+1][x].color };
				bresenham_line(buf, start, end);
			}
			x++;
		}
		y++;
	}
}

// void draw_map_vertex(t_buffer *buf, t_map *map, t_vertex vertex1, t_vertex vertex2, t_mat4 mvp_matrix)
// {
// 	t_vec3f position1, position2;

// 	// Transform the two vertices
// 	position1 = vertex1.position;
// 	position2 = vertex2.position;

// 	position1 = mat4_apply_to_vec3(mvp_matrix, position1);
// 	position2 = mat4_apply_to_vec3(mvp_matrix, position2);

// 	// Debug output for transformed positions
// 	printf("vertex1: %f %f %f\n", vertex1.position.x, vertex1.position.y, vertex1.position.z);
// 	printf("position1: %f %f %f\n", position1.x, position1.y, position1.z);
// 	printf("vertex2: %f %f %f\n", vertex2.position.x, vertex2.position.y, vertex2.position.z);
// 	printf("position2: %f %f %f\n", position2.x, position2.y, position2.z);

// 	// Draw a line between the two transformed vertices using Bresenham's algorithm
// 	t_point start = {position1.x, position1.y};
// 	t_point end = {position2.x, position2.y};
// 	bresenham_line(buf, start, end, 0xFFFFFF);
// }

int	render(t_fdf *fdf)
{
	t_mat4	mvp_matrix;
	int		y;
	int		x;

	draw_map(&fdf->buffer, fdf->map, fdf);
	// mvp_matrix = mat4_multiply(fdf->projection,
	// 		mat4_multiply(fdf->view, fdf->model));
	// y = 0;
	// while (y < fdf->map->height)
	// {
	// 	x = 0;
	// 	while (x < fdf->map->width)
	// 	{
	// 		t_vertex vertex1 = fdf->map->vertex[y][x];
	// 		t_vertex vertex2 = fdf->map->vertex[y][x + 1];
	// 		t_vertex vertex3 = fdf->map->vertex[y + 1][x];

	// 		// Draw horizontal line
	// 		draw_map_vertex(&fdf->buffer, fdf->map, vertex1, vertex2, mvp_matrix);

	// 		// Draw vertical line
	// 		draw_map_vertex(&fdf->buffer, fdf->map, vertex1, vertex2, mvp_matrix);
	// 		x++;
	// 	}
	// 	y++;
	// }
	return (0);
}

void	swap_buffer(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->buffer.img, 0, 0);
}

int main_loop(t_fdf *fdf)
{
	clear_image(&fdf->buffer, fdf->width, fdf->height);
	render(fdf);
	swap_buffer(fdf);
	return (0);
}
