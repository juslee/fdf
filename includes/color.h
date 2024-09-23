/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:22:37 by welee             #+#    #+#             */
/*   Updated: 2024/09/23 12:48:28 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

//# include <stdlib.h>

// Define the t_color structure
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

// Function to convert a hex string (e.g., "0xFF5733") to a t_color
t_color	parse_color(const char *color_str);
// Function to create a color from RGB values
t_color	create_color_rgb(int r, int g, int b);
// Function to create a color from RGB values
t_color	create_color_rgba(int r, int g, int b, int a);
// Function to convert a hexadecimal integer to a t_color
t_color	hex_to_color(int hex_value);
// Function to convert a t_color structure to a hex value (int)
int		color_to_hex(t_color color);
// Function to compare two t_color structures
int		is_equal_color(t_color c1, t_color c2);
// Function to compare default color structure
int		is_default_color(t_color color);
// Function to blend two colors together
t_color	blend_colors(t_color c1, t_color c2);
// Function to convert a t_color to grayscale
t_color	color_to_grayscale(t_color color);
// Function to adjust the brightness of a color
t_color	adjust_brightness(t_color color, float factor);
// Interpolation between two colors
t_color	lerp_color(t_color c1, t_color c2, float t);

#endif
