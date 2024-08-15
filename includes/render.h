/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:07:31 by welee             #+#    #+#             */
/*   Updated: 2024/08/15 20:15:30 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fdf.h"

/*
** Function Prototypes
*/
void	draw_map(t_map *map, t_fdf *fdf);
int		render(t_fdf *fdf);

#endif
