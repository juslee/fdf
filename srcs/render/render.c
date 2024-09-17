/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:45 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 00:09:46 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"
#include "render.h"
#include "mlx.h"
#include <math.h>

void	draw_line(t_fdf *fdf, t_pixel start, t_pixel end)
{
	t_viewport	viewport;

	viewport = (t_viewport){.min = (t_vec2i){0, 0},
		.max = (t_vec2i){fdf->win_width - fdf->image_width, fdf->win_height}};
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
