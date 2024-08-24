/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:06:18 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 18:45:57 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "transform.h"
#include <stdlib.h>

int	init(t_fdf *fdf, t_map *map)
{
	t_translation	translation;
	t_scale			scale;
	t_rotation		rotation;
	t_mat4			transform;

	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (ft_printf("Failed to initialize MiniLibX\n"), free(fdf), 0);
	fdf->win = mlx_new_window(fdf->mlx, fdf->width, fdf->height, "fdf");
	if (!fdf->win)
		return (ft_printf("Failed to create window\n"),
			mlx_destroy_display(fdf->mlx), free(fdf), 0);
	fdf->image.img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->image.addr = mlx_get_data_addr(fdf->image.img,
			&fdf->image.bits_per_pixel, &fdf->image.line_length,
			&fdf->image.endian);
	fdf->map = map;
	transform = create_transform(
			create_translation(0.0f, 0.0f, 0.0f),
			create_scale(fdf->case_size, fdf->case_size, fdf->z_size),
			create_rotation(0.0f, 0.0f, 0.0f));
	return (1);
}
