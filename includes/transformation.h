/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:54:07 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 17:24:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H
# include "point.h"

typedef struct s_transformation
{
	int		case_size;
	int		z_size;
	int		zoom;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		offset_x;
	int		offset_y;
	float	scaling_matrix[4][4];
	float	rotation_matrix[4][4];
	float	translation_matrix[4][4];
	float	transformation_matrix[4][4];
}	t_transformation;

void		create_scaling_matrix(float scaling_matrix[4][4],
				int case_size, int z_size, int zoom);
void		create_rotation_matrix(float rotation_matrix[4][4],
				float angle_x, float angle_y, float angle_z);
void		create_translation_matrix(float translation_matrix[4][4],
				int offset_x, int offset_y);
void		create_transformation_matrix(
				float result[4][4],
				float scaling_matrix[4][4],
				float rotation_matrix[4][4],
				float translation_matrix[4][4]);
void		matrix_multiply(float result[4][4], float a[4][4], float b[4][4]);
t_point3d	apply_matrix(t_point3d point, float matrix[4][4]);

#endif
