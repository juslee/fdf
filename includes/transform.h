/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:52:11 by welee             #+#    #+#             */
/*   Updated: 2024/08/27 17:38:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "matrix.h"
# include "fdf.h"

t_translation	create_translation(float tx, float ty, float tz);
t_scaling		create_scaling(float sx, float sy, float sz);
t_rotation		create_rotation(float angle_x, float angle_y, float angle_z);
t_mat4			create_model_matrix(t_translation translation,
					t_rotation rotation, t_scaling scaling);
t_mat4			create_view_matrix(t_translation translation,
					t_rotation rotation, t_scaling scaling);
t_mat4			create_isometric_projection_matrix(t_map_x map_x,
					t_map_y map_y, t_elevation elevation);
t_mat4			create_perspective_projection_matrix(t_map_x map_x,
					t_map_y map_y, t_elevation elevation);
void			update_translation(t_mat4 *transform,
					t_translation translation);
void			update_scaling(t_mat4 *transform, t_scaling scale);
void			update_rotation(t_mat4 *transform, t_rotation rotation);

#endif
