/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:42:13 by welee             #+#    #+#             */
/*   Updated: 2024/09/02 12:59:42 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/**
 * @brief Print an error message to the standard error output
 *
 * @param message The error message
 */
void	handle_error(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
}
