/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:58:10 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 00:03:34 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

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
