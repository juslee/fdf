/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:06 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 00:05:23 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "map.h"
# include "matrix.h"
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 800
# define IMAGE_WIDTH 400
# define WINDOW_TITLE "FDF"
# define DEFAULT_CASE_SIZE 20.0
# define DEFAULT_Z_SIZE 10.0
# define DEFAULT_PADDING 50.0

// Image Buffer
typedef struct s_buffer
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_buffer;

typedef struct s_pixel
{
	t_vec2i	point;
	double	brightness;
	t_color	color;
}	t_pixel;

// typedef struct s_wu
// {
// 	double	gradient;
// 	double	inter;
// 	double	end;
// 	double	gap;
// }	t_wu;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_buffer	buffer;
	int			win_width;
	int			win_height;
	int			image_width;
	int			image_height;
	t_rotation	rot;
	float		zoom;
	float		case_size;
	float		z_size;
	float		offset_x;
	float		offset_y;
	t_map		*map;
	t_mat4		model;
	t_mat4		view;
	t_mat4		projection;
	t_mat4		mvp;
	float		padding;
	void		*img_ptr;
}	t_fdf;

#endif
