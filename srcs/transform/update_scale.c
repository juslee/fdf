/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:09:00 by welee             #+#    #+#             */
/*   Updated: 2024/08/24 18:13:36 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	update_scale(t_mat4 *transform, t_scale scale)
{
	t_mat4	mat_scaling;

	mat_scaling = mat4_scale(scale);
	*transform = mat4_multiply(*transform, mat_scaling);
}
