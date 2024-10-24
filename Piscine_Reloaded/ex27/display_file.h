/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:36:05 by rlarbi            #+#    #+#             */
/*   Updated: 2024/10/24 15:37:42 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_FILE_H
# define DISPLAY_FILE_H

# define BUFFER_SIZE 4096

# include <fcntl.h>
# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		main(int ac, const char **av);
int		arg_error(void);
int		read_error(void);
int		toomany_error(void);

#endif
