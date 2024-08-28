/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:06:18 by welee             #+#    #+#             */
/*   Updated: 2024/08/28 17:02:46 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "transform.h"
#include <math.h>
#include <stdlib.h>

int	init(t_fdf *fdf, t_map *map)
{
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
	fdf->view = create_view_matrix(create_translation(0, 0, 0),
			create_rotation(0, 0, 0),
			create_scaling(fdf->zoom, fdf->zoom, fdf->zoom));
	fdf->projection = create_isometric_projection_matrix(
			(t_map_x){-1, 1}, (t_map_y){-1, 1},
			(t_elevation){0, 1000});
	return (1);
}
