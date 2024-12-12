/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 05:30:35 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/12 06:10:46 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(size_t num, char *base_char, int *len)
{
	char	str[25];
	int		i;

	i = 0;
	while (num != 0)
	{
		str[i] = base_char[num % 16];
		num = num / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_pointer(size_t ptr, int *len)
{
	char	*base_char;

	base_char = "0123456789abcdef";
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		(*len) += 3;
		return ;
	}
	write(1, "0x", 2);
	(*len) += 2;
	ft_putnbr_hex(ptr, base_char, len);
}
