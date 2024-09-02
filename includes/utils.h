/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:43:11 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 09:59:57 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"
# include <unistd.h>
# include "libft.h"

# define ESC_KEY 65307 // esc
# define PLUS_KEY 112 // p
# define MINUS_KEY 109 // m
# define LEFT_KEY 65361 // left
# define UP_KEY 65362 // up
# define RIGHT_KEY 65363 // right
# define DOWN_KEY 65364 // down
# define ROTATE_X_PLUS 119 // w
# define ROTATE_X_MINUS 115 // s
# define ROTATE_Y_PLUS 97 // a
# define ROTATE_Y_MINUS 100 // d
# define ROTATE_Z_PLUS 113 // q
# define ROTATE_Z_MINUS 101 // e
# define ORTHOGRAPHIC_PROJECTION_TOP 111 // o
# define ORTHOGRAPHIC_PROJECTION_FRONT 102 // f
# define ORTHOGRAPHIC_PROJECTION_RIGHT 114 // r
# define ISOMETRIC_PROJECTION 105 // i

/*
** Function Prototypes
*/
void	handle_error(char *message);
int		handle_keypress(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
int		init_fdf(t_fdf *fdf, t_map *map);

#endif
