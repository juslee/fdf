/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:06 by welee             #+#    #+#             */
/*   Updated: 2024/08/17 00:10:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "parser.h"
# include "utils.h"
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

// Image Buffer
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_pixel
{
	t_point	point;
	double	brightness;
	int		color;
}	t_pixel;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

typedef struct s_wu
{
	double	gradient;
	double	inter;
	double	end;
	double	gap;
}	t_wu;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_image	img1;
	t_image	img2;
	int		width;
	int		height;
	int		current_img;
	float	zoom;
	int		offset_x;
	int		offset_y;
	float	angle_x;
	float	angle_y;
	float	angle_z;
}	t_fdf;

// Function prototypes
int		init(t_fdf *fdf, t_map *map);
void	put_pixel(t_image *img, t_point p, int color, double brightness);
void	bresenham_line(t_image *img, t_point start, t_point end, int color);
int		cohen_sutherland_clip(t_point *start, t_point *end);
void	wu_line(t_image *img, t_point start, t_point end, int color);
void	hook_events(t_fdf *fdf);
void	cleanup(t_fdf *fdf);

#endif
