/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:36:41 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/22 14:47:22 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_index;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min_index])
				min_index = j;
			j++;
		}
		tmp = tab[i];
		tab[i] = tab[min_index];
		tab[min_index] = tmp;
		i++;
	}
}
/*int main()
{
    int tab[] = {64, 25, 12, 6, 20};
    int size = sizeof(tab) / sizeof(tab[0]);

    printf("Tableau avant tri :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");

    ft_sort_int_tab(tab, size);

    printf("Tableau après tri :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}*/
