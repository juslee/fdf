/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:43:12 by welee             #+#    #+#             */
/*   Updated: 2024/09/17 12:27:03 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/**
 * @brief Parse the arguments passed to the program
 *
 * @param argc The number of arguments
 * @param argv The arguments
 * @param fdf The fdf struct
 * @return int 1 if the arguments are valid, 0 otherwise
 */
int	parse_args(int argc, char **argv, t_fdf *fdf)
{
	if (argc >= 3)
	{
		fdf->case_size = ft_atoi(argv[2]);
		if (fdf->case_size <= 0)
			return (error_args(argv[0], fdf));
	}
	if (argc == 4)
	{
		fdf->z_size = ft_atoi(argv[3]);
		if (fdf->z_size <= 0)
			return (error_args(argv[0], fdf));
	}
	return (1);
}
