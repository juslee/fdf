/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_multiply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:46:53 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 14:25:05 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/**
 * @brief Multiply two 4x4 matrices
 * @param a The first matrix
 * @param b The second matrix
 * @return t_mat4 The result of the multiplication
 */
t_mat4	mat4_multiply(t_mat4 a, t_mat4 b)
{
	t_mat4	result;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.m[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				result.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}
