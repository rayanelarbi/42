/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipafnuto <ipafnuto@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:08:16 by ipafnuto          #+#    #+#             */
/*   Updated: 2024/09/14 14:42:41 by ipafnuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rush(int x, int y);

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc < 3)
	{
		write(1, "Require 2 arguments", 8 +2 +9);
		return (0);
	}
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	if (!(x * y))
	{
		write(1, "Size is zero or not a number", 5 +3 +5 +3 +4 +2 +6);
		return (0);
	}
	if (x < 0 || y < 0)
	{
		write(1, "Size can\'t be negative", 5 +6 +3 +8);
		return (0);
	}
	rush(x, y);
	return (0);
}
