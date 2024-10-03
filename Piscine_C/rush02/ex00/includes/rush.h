/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:30:47 by boschwie          #+#    #+#             */
/*   Updated: 2024/09/29 19:30:48 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict
{
	long long	number;
	char		*words;
}				t_dict;

void			parse_file(char *file_path, t_dict **dict, int *dict_size);
int				convert_number_to_words(t_dict *dict, char *number_str);
char			*ft_strdup(char *src);
long long		ft_atoll(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				check_input(char *input);
char			*trim_spaces(char *str);
int				ft_is_num(char *str);

#endif
