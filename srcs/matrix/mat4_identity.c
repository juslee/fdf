/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_identity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:46:17 by welee             #+#    #+#             */
/*   Updated: 2024/09/18 12:54:24 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "libft.h"

/**
 * @brief Create an identity matrix
 * @return t_mat4 The identity matrix
 */
t_mat4	mat4_identity(void)
{
	t_mat4	mat;
	int		i;
	int		j;

	ft_bzero(&mat, sizeof(t_mat4));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mat.m[i][j] = 1.0f;
			j++;
		}
		i++;
	}
	return (mat);
}
