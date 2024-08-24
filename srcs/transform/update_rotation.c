/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:38:59 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 17:12:28 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	update_rotation(t_mat4 *transform, t_rotation rotation)
{
	t_mat4	mat_rotation;

	mat_rotation = mat4_rotate(rotation);
	*transform = mat4_multiply(*transform, mat_rotation);
}
