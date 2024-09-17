/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:51:34 by welee             #+#    #+#             */
/*   Updated: 2024/09/17 20:02:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"
#include "utils.h"
#include <math.h>
// #include <float.h>

int	init_fdf(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->win_width = WINDOW_WIDTH;
	fdf->win_height = WINDOW_HEIGHT;
	fdf->padding = DEFAULT_PADDING;
	fdf->case_size = DEFAULT_CASE_SIZE;
	fdf->z_size = DEFAULT_Z_SIZE;
	fdf->rot.angle_x = 0.0;
	fdf->rot.angle_y = 0.0;
	fdf->rot.angle_z = 0.0;
	fdf->zoom = 1.0;
	fdf->offset_x = 0.0;
	fdf->offset_y = 0.0;
	fdf->mvp = mat4_identity();
	fdf->model = mat4_identity();
	fdf->view = mat4_identity();
	fdf->projection = mat4_identity();
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->buffer.img = NULL;
	fdf->buffer.addr = NULL;
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (!fdf->map)
		return (error_msg("Failed to allocate memory for map", fdf));
	return (1);
}

int	init_mlx(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (error_msg("Failed to initialize MLX", fdf));
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width, fdf->win_height,
			WINDOW_TITLE);
	if (!fdf->win_ptr)
		return (error_msg("Failed to create window", fdf));
	fdf->buffer.img = mlx_new_image(fdf->mlx_ptr, fdf->win_width,
			fdf->win_height);
	if (!fdf->buffer.img)
		return (error_msg("Failed to create image", fdf));
	fdf->buffer.addr = mlx_get_data_addr(fdf->buffer.img,
			&fdf->buffer.bits_per_pixel,
			&fdf->buffer.line_length,
			&fdf->buffer.endian);
	if (!fdf->buffer.addr)
		return (error_msg("Failed to get image data address", fdf));
	return (1);
}

int	init_orthographic(t_fdf *fdf)
{
	t_map_x		map_x;
	t_map_y		map_y;
	t_elevation	elevation;

	fdf->model = mat4_model(
			(t_scaling){fdf->case_size, fdf->case_size, fdf->z_size},
			(t_rotation){fdf->rot.angle_x, fdf->rot.angle_y, fdf->rot.angle_z},
			(t_translation){0.0, 0.0, 0.0});
	fdf->view = mat4_identity();
	map_x = (t_map_x){.left = -fdf->win_width / 2, .right = fdf->map->width};
	map_y = (t_map_y){.bottom = -fdf->win_height / 2, .top = fdf->map->height};
	elevation = (t_elevation){0.1f, 100.0f};
	fdf->projection = mat4_orthographic(map_x, map_y, elevation);
	fdf->mvp = mat4_multiply(fdf->projection,
			mat4_multiply(fdf->view, fdf->model));
	calculate_projected_dimensions(fdf);
	return (1);
}

int	init_isometric(t_fdf *fdf)
{
	fdf->model = mat4_model(
			(t_scaling){fdf->case_size, fdf->case_size, fdf->z_size},
			(t_rotation){fdf->rot.angle_x, fdf->rot.angle_y, fdf->rot.angle_z},
			(t_translation){0.0, 0.0, 0.0});
	fdf->view = mat4_identity();
	fdf->projection = mat4_isometric();
	fdf->mvp = mat4_multiply(fdf->projection,
			mat4_multiply(fdf->view, fdf->model));
	calculate_projected_dimensions(fdf);
	return (1);
}

int	init_hooks(t_fdf *fdf)
{
	mlx_loop_hook(fdf->mlx_ptr, render, fdf);
	mlx_hook(fdf->win_ptr, ON_DESTROY, 1L<<0, close_window, fdf);
	mlx_key_hook(fdf->win_ptr, handle_keypress, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (1);
}
