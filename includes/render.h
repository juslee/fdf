/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:07:31 by welee             #+#    #+#             */
/*   Updated: 2024/08/10 16:08:03 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fdf.h"
# include "map.h"

/*
** Function Prototypes
*/
void	draw_line(t_fdf *fdf, int x0, int y0, int x1, int y1, int color);
void	draw_map(t_map *map, t_fdf *fdf);

#endif
