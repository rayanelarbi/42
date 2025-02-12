/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:13:42 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:27:55 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	counter;

	counter = 0;
	while (lst != NULL)
	{
		++counter;
		lst = lst->next;
	}
	return (counter);
}
