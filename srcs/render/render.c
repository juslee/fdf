/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:45 by welee             #+#    #+#             */
/*   Updated: 2024/09/17 18:29:10 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"
#include "render.h"
#include "mlx.h"
#include <math.h>

// #include <stdio.h>

// void	draw_map(t_buffer *buf, t_map *map, t_fdf *fdf)
// {
// 	int		y;
// 	int		x;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			t_vec3f point = map->vertex[y][x].position;
// 			point = mat4_apply_to_vec3(mat4_multiply(fdf->view,
// fdf->model), point);
// 			// point = mat4_apply_to_vec3(
// 			// 		mat4_multiply(
// 			// 			mat4_rotate_x(M_PI / 6),
// 			// 			mat4_rotate_z(M_PI / 4)),
// 			// 		point);
// 			t_pixel start = { { (int)round(point.x + fdf->offset_x),
/// (int)round(point.y + fdf->offset_y) }, 1.0, map->vertex[y][x].color };
// 			if (x + 1 < map->width)
// 			{
// 				t_vec3f point_next = map->vertex[y][x+1].position;
// 				point_next = mat4_apply_to_vec3(mat4_multiply(fdf->view,
// fdf->model), point_next);
// 				// point_next = mat4_apply_to_vec3(
// 				// 		mat4_multiply(
// 				// 			mat4_rotate_x(M_PI / 6),
// 				// 			mat4_rotate_z(M_PI / 4)),
// 				// 		point_next);
// 				t_pixel end = { { (int)round(point_next.x + fdf->offset_x),
// (int)round(point_next.y + fdf->offset_y) }, 1.0, map->vertex[y][x+1].color };
// 				bresenham_line(buf, start, end);
// 			}
// 			if (y + 1 < map->height)
// 			{
// 				t_vec3f point_next = map->vertex[y+1][x].position;
// 				point_next = mat4_apply_to_vec3(mat4_multiply(fdf->view,
// fdf->model), point_next);
// 				// point_next = mat4_apply_to_vec3(
// 				// 		mat4_multiply(
// 				// 			mat4_rotate_x(M_PI / 6),
// 				// 			mat4_rotate_z(M_PI / 4)),
// 				// 		point_next);
// 				t_pixel end = { { (int)round(point_next.x + fdf->offset_x),
// (int)round(point_next.y + fdf->offset_y) }, 1.0, map->vertex[y+1][x].color };
// 				bresenham_line(buf, start, end);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_map_vertex(t_buffer *buf, t_vertex vertex[2],
// 	t_mat4 mvp_matrix, t_fdf *fdf)
// {
// 	t_vec3f	position1;
// 	t_vec3f	position2;
// 	t_pixel	start;
// 	t_pixel	end;

// 	position1 = vertex[0].pos;
// 	position2 = vertex[1].pos;
// 	position1 = mat4_apply_to_vec3(mvp_matrix, position1);
// 	position2 = mat4_apply_to_vec3(mvp_matrix, position2);
// 	start.point = (t_vec2i){(int)round(position1.x) + fdf->offset_x,
// 		(int)round(position1.y) + fdf->offset_y};
// 	start.color = vertex[0].color;
// 	start.brightness = 1.0;
// 	end.point = (t_vec2i){(int)round(position2.x) + fdf->offset_x,
// 		(int)round(position2.y) + fdf->offset_y};
// 	end.color = vertex[1].color;
// 	end.brightness = 1.0;
// 	bresenham_line(buf, start, end);
// }

// // void	draw_triangle(t_buffer *buf, t_vertex vertex[3], t_mat4 mvp_matrix,
// // t_fdf *fdf)
// // {
// // 	t_vec3f	pos[3];
// // 	t_pixel	start;
// // 	t_pixel	mid;
// // 	t_pixel	end;

// // 	pos[0] = mat4_apply_to_vec3(mvp_matrix, vertex[0].position);
// // 	pos[1] = mat4_apply_to_vec3(mvp_matrix, vertex[1].position);
// // 	pos[2] = mat4_apply_to_vec3(mvp_matrix, vertex[2].position);
// // 	start = (t_pixel){{(int)round(pos[0].x + fdf->offset_x),
// // 		(int)round(pos[1].y + fdf->offset_y)}, 1.0, vertex[0].color};
// // 	mid = (t_pixel){{(int)round(pos[1].x + fdf->offset_x),
// // 		(int)round(pos[1].y + fdf->offset_y)}, 1.0, vertex[1].color};
// // 	end = (t_pixel){{(int)round(pos[2].x + fdf->offset_x),
// // 		(int)round(pos[2].y + fdf->offset_y)}, 1.0, vertex[2].color};
// // 	bresenham_line(buf, start, mid);
// // 	bresenham_line(buf, mid, end);
// // 	bresenham_line(buf, end, start);
// // }

// /**
//  * @brief Draw a horizontal line
//  *
//  * @param fdf The fdf struct
//  * @param mvp_matrix The mvp matrix
//  * @param y The y coordinate
//  * @param x The x coordinate
//  */
// void	draw_horizontal_line(t_fdf *fdf, t_mat4 mvp_matrix, int y, int x)
// {
// 	t_vertex	vertex[2];

// 	vertex[0] = fdf->map->vertices[y][x];
// 	if (x + 1 < fdf->map->width)
// 	{
// 		vertex[1] = fdf->map->vertices[y][x + 1];
// 		draw_map_vertex(&fdf->buffer, vertex, mvp_matrix, fdf);
// 	}
// }

// /**
//  * @brief Draw a vertical line
//  *
//  * @param fdf The fdf struct
//  * @param mvp_matrix The mvp matrix
//  * @param y The y position
//  * @param x The x position
// */
// void	draw_vertical_line(t_fdf *fdf, t_mat4 mvp_matrix, int y, int x)
// {
// 	t_vertex	vertex[2];

// 	vertex[0] = fdf->map->vertices[y][x];
// 	if (y + 1 < fdf->map->height)
// 	{
// 		vertex[1] = fdf->map->vertices[y + 1][x];
// 		draw_map_vertex(&fdf->buffer, vertex, mvp_matrix, fdf);
// 	}
// }

void	draw_line(t_fdf *fdf, t_pixel start, t_pixel end)
{
	t_viewport	viewport;

	viewport = (t_viewport){.min = (t_vec2i){0, 0},
		.max = (t_vec2i){fdf->win_width, fdf->win_height}};
	if (!cohen_sutherland_clip(&start.point, &end.point, &viewport))
		return ;
	bresenham_line(&fdf->buffer, start, end);
}

t_pixel	transform_vertex(t_vertex vertex, t_fdf *fdf)
{
	t_vec3f	transformed;

	transformed = mat4_multiply_vec3(fdf->mvp, vertex.pos);
	transformed.x = transformed.x * fdf->zoom + fdf->offset_x;
	transformed.y = transformed.y * fdf->zoom + fdf->offset_y;
	return ((t_pixel){.point = (t_vec2i){(int)round(transformed.x),
		(int)round(transformed.y)}, .brightness = 1.0, .color = vertex.color});
}

/**
 * @brief Render the fdf
 *
 * @param fdf The fdf struct
 * @return int 0 if success
 */
int	render(t_fdf *fdf)
{
	int			y;
	int			x;

	clear_buffer(&fdf->buffer, fdf->win_width, fdf->win_height);
	fdf->mvp = mat4_multiply(fdf->projection,
			mat4_multiply(fdf->view, fdf->model));
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				draw_line(fdf,
					transform_vertex(fdf->map->vertices[y][x], fdf),
					transform_vertex(fdf->map->vertices[y][x + 1], fdf));
			if (y < fdf->map->height - 1)
				draw_line(fdf,
					transform_vertex(fdf->map->vertices[y][x], fdf),
					transform_vertex(fdf->map->vertices[y + 1][x], fdf));
		}
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->buffer.img, 0, 0);
	return (0);
}
