/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:30:14 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 12:56:16 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

/**
 * @brief Update the translation of the transform matrix
 *
 * @param transform pointer to the transform matrix
 * @param translation the translation to be updated
 */
void	update_translation(t_mat4 *transform, t_translation translation)
{
	t_mat4	mat_translation;

	mat_translation = mat4_translate(translation);
	*transform = mat4_multiply(*transform, mat_translation);
}
