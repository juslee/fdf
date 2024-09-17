/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:43:11 by welee             #+#    #+#             */
/*   Updated: 2024/09/17 20:02:48 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"
# include <unistd.h>
# include "libft.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define KEY_ESC 65307 // esc
# define KEY_PLUS 61 // =
# define KEY_MINUS 45 // -
# define KEY_LEFT 65361 // left
# define KEY_UP 65362 // up
# define KEY_RIGHT 65363 // right
# define KEY_DOWN 65364 // down
# define KEY_W 119 // w
# define KEY_S 115 // s
# define KEY_A 97 // a
# define KEY_D 100 // d
# define KEY_Q 113 // q
# define KEY_E 101 // e
# define ORTHOGRAPHIC_PROJECTION_TOP 111 // o
# define ORTHOGRAPHIC_PROJECTION_FRONT 102 // f
# define ORTHOGRAPHIC_PROJECTION_RIGHT 114 // r
# define ISOMETRIC_PROJECTION 105 // i

// Handle Key Press
int		handle_keypress(int keycode, t_fdf *fdf);
int		handle_resize(int width, int height, t_fdf *fdf);
int		close_window(t_fdf *fdf);

// Function Prototypes
int		parse_args(int argc, char **argv, t_fdf *fdf);
int		init_fdf(t_fdf *fdf);
int		init_mlx(t_fdf *fdf);
int		init_isometric(t_fdf *fdf);
int		init_orthographic(t_fdf *fdf);
int		init_hooks(t_fdf *fdf);
void	calculate_projected_dimensions(t_fdf *fdf);

// Error Handling
int		error_args(char *name, t_fdf *fdf);
int		error_file(char *message, t_map *map);
int		error_map(char *message, t_map *map);
int		error_msg(char *message, t_fdf *fdf);
int		error_exit(char *message, t_fdf *fdf);

// Freeing Memory
void	free_split(char **split);
void	free_map(t_map *map);
void	free_fdf(t_fdf *fdf);

#endif
