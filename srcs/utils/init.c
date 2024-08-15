/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:06:18 by welee             #+#    #+#             */
/*   Updated: 2024/08/15 17:03:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	init(t_fdf *fdf, t_map *map)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (ft_printf("Failed to initialize MiniLibX\n"), free(fdf), 0);
	fdf->win= mlx_new_window(fdf->mlx, fdf->width, fdf->height, "fdf");
	if (!fdf->win)
		return (ft_printf("Failed to create window\n"),
			mlx_destroy_display(fdf->mlx), free(fdf), 0);
	fdf->img1.img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->img1.addr = mlx_get_data_addr(fdf->img1.img, &fdf->img1.bits_per_pixel,
			&fdf->img1.line_length, &fdf->img1.endian);
	fdf->img2.img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->img2.addr = mlx_get_data_addr(fdf->img2.img, &fdf->img2.bits_per_pixel,
			&fdf->img2.line_length, &fdf->img2.endian);
	fdf->current_img = 0;
	fdf->map = map;
	fdf->zoom = 20; // Default zoom value, can be adjusted later
	fdf->offset_x = fdf->width / 2;
	fdf->offset_y = fdf->height / 2;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
	return (1);
}
