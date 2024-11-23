/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:00:42 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/22 19:07:33 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	print_char(int c, int *counter);
void	print_str(char *str, int *counter);
int		ft_printf(const char *str, ...);
int		print_param(char specifier, va_list ptr);
void	print_nbr(long ln, int base, int *counter);

#endif