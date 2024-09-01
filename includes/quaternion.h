/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:09:56 by welee             #+#    #+#             */
/*   Updated: 2024/08/30 13:11:40 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "matrix.h"

typedef struct s_quaternion
{
	float	w;
	float	x;
	float	y;
	float	z;
}	t_quaternion;

t_quaternion	euler_to_quaternion(float angle_x,
					float angle_y, float angle_z);
t_quaternion	quaternion_normalize(t_quaternion q);
t_quaternion	quaternion_multiply(t_quaternion q1, t_quaternion q2);
t_mat4			quaternion_to_mat4(t_quaternion q);
t_quaternion	mat4_to_quaternion(t_mat4 mat);

#endif
