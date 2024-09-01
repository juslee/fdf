/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:07:31 by welee             #+#    #+#             */
/*   Updated: 2024/08/29 14:01:17 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fdf.h"
# include "color.h"
# include "vector.h"
# include "heightmap.h"

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

/*
** Function Prototypes
*/
void	draw_map(t_buffer *buf, t_map *map, t_fdf *fdf);
int		render(t_fdf *fdf);
int		main_loop(t_fdf *fdf);
void	put_pixel(t_buffer *img, t_vec2i p, t_color color, double brightness);
void	bresenham_line(t_buffer *img, t_pixel start, t_pixel end);
int		cohen_sutherland_clip(t_vec2i *start, t_vec2i *end);
void	wu_line(t_buffer *img, t_vec2i start, t_vec2i end, t_color color);

#endif
