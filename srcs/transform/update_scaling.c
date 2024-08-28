/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scaling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:09:00 by welee             #+#    #+#             */
/*   Updated: 2024/08/25 20:18:17 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void	update_scaling(t_mat4 *transform, t_scaling scaling)
{
	t_mat4	mat_scaling;

	mat_scaling = mat4_scale(scaling);
	*transform = mat4_multiply(*transform, mat_scaling);
}
