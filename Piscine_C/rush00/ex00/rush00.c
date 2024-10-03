/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipafnuto <ipafnuto@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:45:53 by ipafnuto          #+#    #+#             */
/*   Updated: 2024/09/14 15:59:36 by ipafnuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	getchar(int xs, int xe, int ys, int ye)
{
	if ((xs | xe) & (ys | ye))
		return ('o');
	if (xs | xe)
		return ('|');
	if (ys | ye)
		return ('-');
	return (' ');
}

void	rush(int x, int y)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			ft_putchar(getchar(!xi, xi == x -1, !yi, yi == y -1));
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}
