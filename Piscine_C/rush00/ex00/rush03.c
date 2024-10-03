/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipafnuto <ipafnuto@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:46:08 by ipafnuto          #+#    #+#             */
/*   Updated: 2024/09/14 14:42:13 by ipafnuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		xi;
	int		yi;
	char	c;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			c = 'C';
			if (!xi || xi == x -1)
				c--;
			if (!yi || yi == y -1)
				c--;
			if (c == 'C')
				c = ' ';
			if (c == 'A' && xi)
				c = 'C';
			ft_putchar(c);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}
