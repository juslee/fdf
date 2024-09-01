/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:43:11 by welee             #+#    #+#             */
/*   Updated: 2024/08/29 13:50:54 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"
# include <unistd.h>
# include "libft.h"

/*
** Function Prototypes
*/
void	handle_error(char *message);
int		handle_keypress(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
int		init_fdf(t_fdf *fdf, t_map *map);

#endif
