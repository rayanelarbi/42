/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:08:39 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:29:49 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// While 1 Advance the ptr s1 as long as the current char belongs to set
// While 2 decrease i as long as the char at position i belongs to set
// Return substr from index 0 to i inclusive is extracted and returned
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		++start;
	while (end >= 0 && ft_strchr(set, *(s1 + end)))
		--end;
	if (start > end)
		return (ft_strdup(""));
	trim = malloc((end - start) + 2);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s1 + start, (end - start) + 2);
	return (trim);
}
