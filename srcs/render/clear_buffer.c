/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:20:52 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 11:35:40 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/**
 * @brief Clear the buffer
 *
 * @param buf The buffer
 * @param width The width of the buffer
 * @param height The height of the buffer
 */
void	clear_buffer(t_buffer *buf, int width, int height)
{
	t_vec2i	p;
	t_color	color;

	color = create_color_rgb(0, 0, 0);
	p.y = -1;
	while (p.y++ < height)
	{
		p.x = -1;
		while (p.x++ < width)
		{
			put_pixel(buf, p, color, 1.0);
		}
	}
}
