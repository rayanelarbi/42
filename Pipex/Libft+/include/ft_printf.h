/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:57:40 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/12 09:15:10 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar_len(char c, int *len);
void	ft_string(char *args, int *len);
void	ft_number(int nb, int *len);
void	ft_hexadecimal(unsigned int x, int *len, char x_or_x);
void	ft_unsigned_int(unsigned int u, int *len);
void	ft_pointer(size_t ptr, int *len);

int		ft_printf(const char *str, ...);
#endif
