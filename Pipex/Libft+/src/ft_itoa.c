/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:31:36 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:27:00 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Calculate the number of char in numbers
static size_t	ft_nb_size(int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len = len + 1;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	size_t			len;

	len = ft_nb_size(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	if (nb == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nb != 0)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
/*int	main(void)
{
	char	*str;

	str = ft_itoa(-2147483648);
	printf("Résultat : %s\n", str);
	free(str);
	str = ft_itoa(12345);
	printf("Résultat : %s\n", str);
	free(str);
	str = ft_itoa(0);
	printf("Résultat : %s\n", str);
	free(str);
	return (0);
}*/
