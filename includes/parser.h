/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:31:52 by welee             #+#    #+#             */
/*   Updated: 2024/08/10 16:06:46 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "map.h"
# include "libft.h"

/*
** Function Prototypes
*/
t_map	*parse_map(char *file_name);
int		**allocate_z_matrix(int width, int height);
void	free_z_matrix(int **z_matrix, int height);

#endif
