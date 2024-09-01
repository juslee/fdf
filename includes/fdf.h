/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:06 by welee             #+#    #+#             */
/*   Updated: 2024/08/29 15:38:03 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "heightmap.h"
# include "matrix.h"
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

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

typedef struct s_wu
{
	double	gradient;
	double	inter;
	double	end;
	double	gap;
}	t_wu;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_buffer	buffer;
	t_mat4		model;
	t_mat4		view;
	t_mat4		projection;
	int			width;
	int			height;
	int			case_size;
	int			z_size;
	int			zoom;
	int			offset_x;
	int			offset_y;
}	t_fdf;

#endif
