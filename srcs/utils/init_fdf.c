/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:06:18 by welee             #+#    #+#             */
/*   Updated: 2024/09/01 13:11:16 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "transform.h"
#include "matrix.h"
#include <math.h>
#include <stdlib.h>

int	init_fdf(t_fdf *fdf, t_map *map)
{
	fdf->width = WIN_WIDTH;
	fdf->height = WIN_HEIGHT;
	fdf->offset_x = WIN_WIDTH / 2;
	fdf->offset_y = 100;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (ft_printf("Failed to initialize MiniLibX\n"), free(fdf), 0);
	fdf->win = mlx_new_window(fdf->mlx, fdf->width, fdf->height, "fdf");
	if (!fdf->win)
		return (ft_printf("Failed to create window\n"),
			mlx_destroy_display(fdf->mlx), free(fdf), 0);
	fdf->buffer.img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->buffer.addr = mlx_get_data_addr(fdf->buffer.img,
			&fdf->buffer.bits_per_pixel, &fdf->buffer.line_length,
			&fdf->buffer.endian);
	fdf->map = map;
	fdf->model = create_model_matrix(create_translation(0, 0, 0),
			create_rotation(0, 0, 0),
			create_scaling(fdf->case_size, fdf->case_size, fdf->z_size));
	// fdf->view = create_view_matrix(vec3f_create(20, 20, 50),
	// 		vec3f_create(0, 0, 0), vec3f_create(0, 0, 1));
	fdf->projection = mat4_identity();
	// fdf->view = create_view_matrix(vec3f_create(10, 10, 20),
	//		vec3f_create(0, 0, 0), vec3f_create(0, 0, 1));
	// float fov = 45 * (M_PI / 180.0f); // Field of view in degrees
	// float aspect_ratio = (float)WIN_WIDTH / (float)WIN_HEIGHT;
	// float near_clip = 0.0f;
	// float far_clip = 1000.0f;
	//fdf->projection = mat4_perspective(45, (float)WIN_WIDTH / (float)WIN_HEIGHT, 0.0f, 1000.0f);
	// fdf->projection = mat4_multiply(
	// 	mat4_orthographic(
	// 		(t_map_x){0.0f, map->width},
	// 		(t_map_y){0.0f, map->height},
	// 		(t_elevation){map->min_elevation, map->max_elevation}),
	// 	mat4_isometric());
	// fdf->projection = // mat4_perspective(fov, aspect_ratio, near_clip, far_clip);
	fdf->view = create_view_matrix(create_translation(0, 0, 0),
			create_rotation(0, 0, 0),
			create_scaling(1, 1, 1));
	fdf->projection = create_isometric_projection_matrix(
			(t_map_x){-1, 1}, (t_map_y){-1, 1},
			(t_elevation){0.1, 1000});
	return (1);
}
