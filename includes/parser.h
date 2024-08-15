/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:31:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/13 12:23:03 by welee            ###   ########.fr       */
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
int		parse_map(const char *filename, t_map *map);
void	free_map(t_map *map);

#endif
