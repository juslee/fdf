/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:18:05 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 13:29:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "ft_printf.h"
#include <stdio.h>

/**
 * @brief Print a 4x4 matrix
 * @param mat The matrix
 */
void	mat4_print(t_mat4 mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f ", mat.m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
