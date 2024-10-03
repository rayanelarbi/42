/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:06:28 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/14 16:07:07 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	t;

	if (n >= 0)
	{
		t = 'P';
	}
	else
	{
		t = 'N';
	}
	write(1, &t, 1);
}
/*int main(){
	ft_is_negative(5);
	ft_is_negative(-10);
	return 0;
}*/
