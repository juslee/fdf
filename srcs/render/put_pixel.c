/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:05:32 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 11:34:28 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Put a pixel on the buffer
 *
 * @param buf The buffer
 * @param p The position of the pixel
 * @param color The color of the pixel
 * @param brightness The brightness of the pixel
 */
void	put_pixel(t_buffer *buf, t_vec2i p, t_color color, double brightness)
{
	char	*pixel;
	int		r;
	int		g;
	int		b;

	pixel = buf->addr
		+ (p.y * buf->line_length + p.x * (buf->bits_per_pixel / 8));
	r = color.r * brightness;
	g = color.g * brightness;
	b = color.b * brightness;
	*(unsigned int *)pixel = (r << 16) | (g << 8) | b;
}
