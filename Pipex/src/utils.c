/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:19:40 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/09 18:43:30 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

// Print error on the stderr
void	error_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
