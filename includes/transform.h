/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:52:11 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 18:36:11 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "matrix.h"
# include "fdf.h"

t_translation	create_translation(float tx, float ty, float tz);
t_scale			create_scale(float sx, float sy, float sz);
t_rotation		create_rotation(float angle_x, float angle_y, float angle_z);
t_mat4			create_transform(t_translation translation, t_scale scale,
					t_rotation rotation);
void			update_translation(t_mat4 *transform,
					t_translation translation);
void			update_scale(t_mat4 *transform, t_scale scale);
void			update_rotation(t_mat4 *transform, t_rotation rotation);

#endif
