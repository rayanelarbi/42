/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:22:23 by boschwie          #+#    #+#             */
/*   Updated: 2024/09/29 19:28:10 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

void	convert_hundreds(t_dict *dict, long long number)
{
	if (number >= 100)
	{
		convert_hundreds(dict, number / 100);
		ft_putstr("hundred ");
		number %= 100;
	}
}

void	convert_tens(t_dict *dict, long long number)
{
	if (number >= 20)
	{
		ft_putstr(dict[number / 10 * 10].words);
		ft_putstr(" ");
		number %= 10;
	}
}

int	convert_number_to_words(t_dict *dict, char *number_str)
{
	long long	number;

	number = ft_atoll(number_str);
	if (number < 0)
		return (0);
	if (number == 0)
	{
		ft_putstr(dict[0].words);
		return (1);
	}
	convert_hundreds(dict, number);
	convert_tens(dict, number);
	if (number > 0)
		ft_putstr(dict[number].words);
	return (1);
}
