/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:31:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/12 18:58:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_matrix;
}	t_map;

/*
** Function Prototypes
*/
t_map	*parse_map(const char *filename);
void	free_map(t_map *map);

#endif
