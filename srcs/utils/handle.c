/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:31:46 by welee             #+#    #+#             */
/*   Updated: 2024/09/23 12:42:20 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "fdf.h"
#include <math.h>

/**
 * @brief Handle the zoom and offset of the fdf
 * @param keycode The key code
 * @param fdf The fdf
 * @return int The status
 */
static int	handle_zoom_offset(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->zoom *= 1.1;
	else if (keycode == KEY_MINUS)
		fdf->zoom /= 1.1;
	else if (keycode == KEY_LEFT)
		fdf->offset_x -= 10;
	else if (keycode == KEY_RIGHT)
		fdf->offset_x += 10;
	else if (keycode == KEY_UP)
		fdf->offset_y -= 10;
	else if (keycode == KEY_DOWN)
		fdf->offset_y += 10;
	return (0);
}

/**
 * @brief Check the rotation of the fdf
 * @param fdf The fdf
 */
static void	check_rot(t_fdf *fdf)
{
	if (fdf->rot.angle_x > 2 * M_PI)
		fdf->rot.angle_x -= 2 * M_PI;
	else if (fdf->rot.angle_x < 0)
		fdf->rot.angle_x += 2 * M_PI;
	if (fdf->rot.angle_y > 2 * M_PI)
		fdf->rot.angle_y -= 2 * M_PI;
	else if (fdf->rot.angle_y < 0)
		fdf->rot.angle_y += 2 * M_PI;
	if (fdf->rot.angle_z > 2 * M_PI)
		fdf->rot.angle_z -= 2 * M_PI;
	else if (fdf->rot.angle_z < 0)
		fdf->rot.angle_z += 2 * M_PI;
}

/**
 * @brief Handle the rotation of the fdf
 * @param keycode The key code
 * @param fdf The fdf
 * @return int The status
 */
static int	handle_rot(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_W)
		fdf->rot.angle_x += 15 * M_PI / 180;
	else if (keycode == KEY_S)
		fdf->rot.angle_x -= 15 * M_PI / 180;
	else if (keycode == KEY_A)
		fdf->rot.angle_y += 15 * M_PI / 180;
	else if (keycode == KEY_D)
		fdf->rot.angle_y -= 15 * M_PI / 180;
	else if (keycode == KEY_Q)
		fdf->rot.angle_z += 15 * M_PI / 180;
	else if (keycode == KEY_E)
		fdf->rot.angle_z -= 15 * M_PI / 180;
	check_rot(fdf);
	fdf->model = mat4_model(
			(t_scaling){fdf->case_size, fdf->case_size, fdf->z_size},
			(t_rotation){fdf->rot.angle_x, fdf->rot.angle_y, fdf->rot.angle_z},
			(t_translation){0.0, 0.0, 0.0});
	return (0);
}

/**
 * @brief Handle the orthographic projection of the fdf
 *
 * @param keycode The key code
 * @param fdf The fdf
 * @return int The status
 */
void	handle_orthographic(int keycode, t_fdf *fdf)
{
	if (keycode == ORTHO_TOP)
	{
		fdf->rot = (t_rotation){0, 0, 0};
		init_orthographic(fdf);
	}
	else if (keycode == ORTHO_FRONT)
	{
		fdf->rot = (t_rotation){-90 * M_PI / 180, 0, 0};
		init_orthographic(fdf);
	}
	else if (keycode == ORTHO_RIGHT)
	{
		fdf->rot = (t_rotation){-90 * M_PI / 180, -90 * M_PI / 180, 0};
		init_orthographic(fdf);
	}
	else if (keycode == ISO)
	{
		fdf->rot = (t_rotation){-90 * M_PI / 180, 0, 0};
		init_isometric(fdf);
	}
}

/**
 * @brief Handle the key press
 *
 * @param keycode The key code
 * @param fdf The fdf
 * @return int The status
 */
int	handle_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		close_window(fdf);
	else
	{
		handle_zoom_offset(keycode, fdf);
		handle_rot(keycode, fdf);
		handle_orthographic(keycode, fdf);
	}
	return (0);
}
