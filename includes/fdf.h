/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:06 by welee             #+#    #+#             */
/*   Updated: 2024/08/11 21:08:29 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "map.h"
# include "utils.h"
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	float	zoom;
	int		offset_x;
	int		offset_y;
	float	angle_x;
	float	angle_y;
	float	angle_z;
}	t_fdf;

// Function prototypes
t_map	*parse_map(const char *file);
t_fdf	*init_fdf(t_map *map);
void	render(t_fdf *fdf);
void	hook_events(t_fdf *fdf);
void	cleanup(t_fdf *fdf);

#endif
