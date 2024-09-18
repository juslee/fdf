/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:51:34 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:53:48 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"
#include "utils.h"
#include <math.h>

/**
 * @brief Initialize the fdf structure
 * @param fdf The fdf structure
 * @return int The return value
 */
int	init_fdf(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->win_width = WINDOW_WIDTH;
	fdf->win_height = WINDOW_HEIGHT;
	fdf->image_width = IMAGE_WIDTH;
	fdf->image_height = IMAGE_HEIGHT;
	fdf->padding = DEFAULT_PADDING;
	fdf->case_size = DEFAULT_CASE_SIZE;
	fdf->z_size = DEFAULT_Z_SIZE;
	fdf->zoom = 1.0;
	fdf->mvp = mat4_identity();
	fdf->model = mat4_identity();
	fdf->view = mat4_identity();
	fdf->projection = mat4_identity();
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (!fdf->map)
		return (error_msg("Failed to allocate memory for map", fdf));
	return (1);
}

/**
 * @brief Initialize the mlx
 * @param fdf The fdf structure
 * @return int The return value
 */
int	init_mlx(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (error_msg("Failed to initialize MLX", fdf));
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width, fdf->win_height,
			WINDOW_TITLE);
	if (!fdf->win_ptr)
		return (error_msg("Failed to create window", fdf));
	fdf->buffer.img = mlx_new_image(fdf->mlx_ptr, 880,
			fdf->win_height);
	if (!fdf->buffer.img)
		return (error_msg("Failed to create image", fdf));
	fdf->buffer.addr = mlx_get_data_addr(fdf->buffer.img,
			&fdf->buffer.bits_per_pixel,
			&fdf->buffer.line_length,
			&fdf->buffer.endian);
	if (!fdf->buffer.addr)
		return (error_msg("Failed to get image data address", fdf));
	return (1);
}

/**
 * @brief Initialize the image
 * @param fdf The fdf structure
 * @return int The return value
 */
int	init_image(t_fdf *fdf)
{
	int		img_width;
	int		img_height;

	fdf->img_ptr = mlx_xpm_file_to_image(fdf->mlx_ptr, KEYS_IMAGE,
			&img_width, &img_height);
	if (!fdf->img_ptr)
		return (error_exit("Failed to load image", fdf));
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr,
		fdf->win_width - fdf->image_width, fdf->win_height - fdf->image_height);
	return (1);
}

/**
 * @brief Initialize the hooks
 * @param fdf The fdf structure
 * @return int The return value
 */
int	init_hooks(t_fdf *fdf)
{
	mlx_loop_hook(fdf->mlx_ptr, render, fdf);
	mlx_hook(fdf->win_ptr, ON_DESTROY, 1L<<0, close_window, fdf);
	mlx_key_hook(fdf->win_ptr, handle_keypress, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (1);
}
