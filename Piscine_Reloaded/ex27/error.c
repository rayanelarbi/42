/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:36:13 by rlarbi            #+#    #+#             */
/*   Updated: 2024/10/24 15:36:15 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	arg_error(void)
{
	ft_putstr("File name missing.\n");
	return (1);
}

int	read_error(void)
{
	ft_putstr("Cannot read file.\n");
	return (1);
}

int	toomany_error(void)
{
	ft_putstr("Too many arguments.\n");
	return (1);
}
