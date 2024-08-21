/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:22:37 by welee             #+#    #+#             */
/*   Updated: 2024/08/21 17:15:36 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdlib.h>

// Define the t_color structure
typedef struct s_color
{
	int	r; // Red component (0-255)
	int	g; // Green component (0-255)
	int	b; // Blue component (0-255)
}	t_color;

// Function to convert a hex string (e.g., "0xFF5733") to a t_color
t_color	parse_color(const char *color_str);

// Function to convert a hexadecimal integer to a t_color
t_color	hex_to_color(int hex_value);

// Function to create a color from RGB values
t_color	create_color(int r, int g, int b);

// Function to convert a t_color structure to a hex value (int)
int		color_to_hex(t_color color);

// Function to compare two t_color structures
int		is_equal_color(t_color c1, t_color c2);

// Function to compare default color structure
int		is_default_color(t_color color);

#endif
