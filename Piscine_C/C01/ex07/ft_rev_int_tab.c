/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:24:27 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/22 14:34:33 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}
/*int main()
{
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // Tableau à inverser
    int size = sizeof(tab) / sizeof(tab[0]);  // Calculer la taille du tableau

    // Affichage du tableau avant l'inversion
    printf("Tableau avant inversion :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");

    // Appel de la fonction pour inverser le tableau
    ft_rev_int_tab(tab, size);

    // Affichage du tableau après l'inversion
    printf("Tableau après inversion :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}*/
