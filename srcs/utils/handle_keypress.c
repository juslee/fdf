/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:31:46 by welee             #+#    #+#             */
/*   Updated: 2024/09/01 14:12:51 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "transform.h"
#include <math.h>

#define ESC_KEY 65307 // esc
#define PLUS_KEY 112 // p
#define MINUS_KEY 109 // m
#define LEFT_KEY 65361 // left
#define UP_KEY 65362 // up
#define RIGHT_KEY 65363 // right
#define DOWN_KEY 65364 // down
#define ROTATE_X_PLUS 119 // w
#define ROTATE_X_MINUS 115 // s
#define ROTATE_Y_PLUS 97 // a
#define ROTATE_Y_MINUS 100 // d
#define ROTATE_Z_PLUS 113 // q
#define ROTATE_Z_MINUS 101 // e
#define ORTHOGRAPHIC_PROJECTION_TOP 111 // o
#define ORTHOGRAPHIC_PROJECTION_FRONT 102 // f
#define ORTHOGRAPHIC_PROJECTION_RIGHT 114 // r
#define ISOMETRIC_PROJECTION 105 // i

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
	return (0);
}

int	handle_scaling(int keycode, t_fdf *fdf)
{
	if (keycode == PLUS_KEY)
		update_scaling(&fdf->view, (t_scaling){1.1, 1.1, 1.1});
	else if (keycode == MINUS_KEY)
		update_scaling(&fdf->view, (t_scaling){0.9, 0.9, 0.9});
	return (0);
}

int	handle_movement(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT_KEY)
		fdf->offset_x -= 10;
	else if (keycode == RIGHT_KEY)
		fdf->offset_x += 10;
	else if (keycode == UP_KEY)
		fdf->offset_y -= 10;
	else if (keycode == DOWN_KEY)
		fdf->offset_y += 10;
	return (0);
}

int	handle_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == ROTATE_X_PLUS)
		update_rotation(&fdf->view, (t_rotation){ 15 * M_PI / 180, 0, 0});
	else if (keycode == ROTATE_X_MINUS)
		update_rotation(&fdf->view, (t_rotation){-15 * M_PI / 180, 0, 0});
	else if (keycode == ROTATE_Y_PLUS)
		update_rotation(&fdf->view, (t_rotation){0, 15 * M_PI / 180, 0});
	else if (keycode == ROTATE_Y_MINUS)
		update_rotation(&fdf->view, (t_rotation){0, -15 * M_PI / 180, 0});
	else if (keycode == ROTATE_Z_PLUS)
		update_rotation(&fdf->view, (t_rotation){0, 0, 15 * M_PI / 180});
	else if (keycode == ROTATE_Z_MINUS)
		update_rotation(&fdf->view, (t_rotation){0, 0, -15 * M_PI / 180});
	return (0);
}

int	handle_2D_orthographic_projection(int keycode, t_fdf *fdf)
{
	if (keycode == ORTHOGRAPHIC_PROJECTION_TOP)
	{
		fdf->view = create_view_matrix(create_translation(0, 0, 0),
				create_rotation(0, 0, 0),
				create_scaling(1, 1, 1));
		fdf->projection = mat4_identity();
	}
	else if (keycode == ORTHOGRAPHIC_PROJECTION_FRONT)
	{
		fdf->view = create_view_matrix(create_translation(0, 0, 0),
				create_rotation(90 * M_PI / 180, 0, 0),
				create_scaling(1, 1, 1));
		fdf->projection = mat4_identity();
	}
	else if (keycode == ORTHOGRAPHIC_PROJECTION_RIGHT)
	{
		fdf->view = create_view_matrix(create_translation(0, 0, 0),
				create_rotation(90 * M_PI / 180, 0, -90 * M_PI / 180),
				create_scaling(1, 1, 1));
		fdf->projection = mat4_identity();
	}
	else if (keycode == ISOMETRIC_PROJECTION)
		fdf->projection = create_isometric_projection_matrix(
				(t_map_x){-1, 1}, (t_map_y){-1, 1},
				(t_elevation){0.1, 1000});
	return (0);
}

int	handle_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		close_window(fdf);
	else
	{
		handle_scaling(keycode, fdf);
		handle_movement(keycode, fdf);
		handle_rotation(keycode, fdf);
		handle_2D_orthographic_projection(keycode, fdf);
	}
	return (0);
}
