/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:45 by welee             #+#    #+#             */
/*   Updated: 2024/08/11 13:41:32 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"

void	render_map(void *mlx_ptr, void *win_ptr, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x * 10, y * 10, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
