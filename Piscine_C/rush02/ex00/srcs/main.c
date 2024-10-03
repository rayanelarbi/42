/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:22:57 by boschwie          #+#    #+#             */
/*   Updated: 2024/09/29 19:30:25 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

int	main(int argc, char **argv)
{
	t_dict	*dict;
	int		dict_size;

	if (argc == 2)
	{
		parse_file("numbers.dict", &dict, &dict_size);
		if (ft_is_num(argv[1]))
			convert_number_to_words(dict, argv[1]);
		else
			ft_putstr("Error\n");
	}
	else if (argc == 3)
	{
		parse_file(argv[1], &dict, &dict_size);
		if (ft_is_num(argv[2]))
			convert_number_to_words(dict, argv[2]);
		else
			ft_putstr("Error\n");
	}
	else
	{
		ft_putstr("Please enter a number\n");
	}
	return (0);
}
