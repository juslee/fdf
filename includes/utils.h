/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:43:11 by welee             #+#    #+#             */
/*   Updated: 2024/09/23 12:45:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"
# include <unistd.h>
# include "libft.h"

# define KEYS_IMAGE "./assets/keys.xpm"

enum e_keycode
{
	KEY_ESC = 65307,
	KEY_PLUS = 61,
	KEY_MINUS = 45,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100,
	KEY_Q = 113,
	KEY_E = 101,
	ORTHO_TOP = 116,
	ORTHO_FRONT = 102,
	ORTHO_RIGHT = 114,
	ISO = 105
};

enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// Handle Key Press
int		handle_keypress(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);

// Function Prototypes
int		parse_args(int argc, char **argv, t_fdf *fdf);
int		init_fdf(t_fdf *fdf);
int		init_mlx(t_fdf *fdf);
int		init_image(t_fdf *fdf);
int		init_isometric(t_fdf *fdf);
int		init_orthographic(t_fdf *fdf);
int		init_hooks(t_fdf *fdf);
void	set_zoom_offset(t_fdf *fdf);

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
