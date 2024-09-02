/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:20:52 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 10:21:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	clear_image(t_buffer *buf, int width, int height)
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
