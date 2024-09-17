/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:49:03 by welee             #+#    #+#             */
/*   Updated: 2024/09/15 23:02:04 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"
#include "utils.h"

int	error_args(char *name, t_fdf *fdf)
{
	ft_printf("Usage: %s <filename> [ case_size z_size ]\n", name);
	free_fdf(fdf);
	return (EXIT_FAILURE);
}

int	error_file(char *filename, t_map *map)
{
	ft_printf("No file %s\n", filename);
	free_map(map);
	return (0);
}

int	error_map(char *message, t_map *map)
{
	ft_printf("%s\n", message);
	free_map(map);
	return (0);
}

int	error_msg(char *message, t_fdf *fdf)
{
	ft_printf("%s\n", message);
	free_fdf(fdf);
	return (0);
}

int	error_exit(char *message, t_fdf *fdf)
{
	ft_printf("%s\n", message);
	free_fdf(fdf);
	return (EXIT_FAILURE);
}
