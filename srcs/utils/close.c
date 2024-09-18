/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:58:07 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:19:00 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Close the window
 * @param fdf The fdf structure
 * @return int The return value
 */
int	close_window(t_fdf *fdf)
{
	free_fdf(fdf);
	exit(0);
	return (0);
}
