/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:49:03 by welee             #+#    #+#             */
/*   Updated: 2024/09/19 12:15:16 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"
#include "utils.h"

/**
 * @brief Print error message for invalid arguments.
 * @param name The program name.
 * @param fdf The fdf structure.
 * @return int The return value.
 */
int	error_args(char *name, t_fdf *fdf)
{
	ft_printf("Usage: %s <filename> [ case_size z_size ]\n", name);
	free_fdf(fdf);
	return (EXIT_FAILURE);
}

/**
 * @brief Print error message for invalid file.
 * @param filename The filename.
 * @param map The map structure.
 * @return int The return value.
 */
int	error_file(char *filename, t_map *map)
{
	(void)map;
	ft_printf("No file %s\n", filename);
	// free_map(map);
	return (0);
}

/**
 * @brief Print error message for invalid map.
 * @param message The error message.
 * @param map The map structure.
 * @return int The return value.
 */
int	error_map(char *message, t_map *map)
{
	(void)map;
	ft_printf("%s\n", message);
	// free_map(map);
	return (0);
}

/**
 * @brief Print error message for invalid fdf.
 * @param message The error message.
 * @param fdf The fdf structure.
 * @return int The return value.
 */
int	error_msg(char *message, t_fdf *fdf)
{
	ft_printf("%s\n", message);
	free_fdf(fdf);
	return (0);
}

/**
 * @brief Print error message and return exit for invalid fdf.
 * @param message The error message.
 * @param fdf The fdf structure.
 * @return int The return value.
 */
int	error_exit(char *message, t_fdf *fdf)
{
	ft_printf("%s\n", message);
	free_fdf(fdf);
	return (EXIT_FAILURE);
}
