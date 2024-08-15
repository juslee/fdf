/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:05:32 by welee             #+#    #+#             */
/*   Updated: 2024/08/15 14:33:20 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_image *img, t_point p, int color, double brightness)
{
	char	*pixel;
	int		r;
	int		g;
	int		b;

	pixel = img->addr
		+ (p.y * img->line_length + p.x * (img->bits_per_pixel / 8));
	r = ((color >> 16) & 0xFF) * brightness;
	g = ((color >> 8) & 0xFF) * brightness;
	b = (color & 0xFF) * brightness;
	*(unsigned int *)pixel = (r << 16) | (g << 8) | b;
}
