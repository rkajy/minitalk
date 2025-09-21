/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:37:42 by radandri          #+#    #+#             */
/*   Updated: 2025/08/24 21:33:02 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h> // va_list, va_start, va_end
# include <stddef.h> // size_t
# include <stdint.h> // uintptr_t
# include <stdlib.h> // malloc, free
# include <unistd.h> // write

# if defined(__linux__)
#  define PTRNULL "(nil)"
#  define NPTRSIZE 5

# elif defined(__APPLE__)
#  define PTRNULL "0x0"
#  define NPTRSIZE 3
# endif

# define HEX_BASE "0123456789abcdef"
# define HEX_BASE_CAPITAL "0123456789ABCDEF"

typedef struct s_format
{
	char	type;
}			t_format;

// core functions
int			ft_printf(const char *format, ...);

// specifier functions
int			print_char(va_list *args);
int			print_string(va_list *args);
int			print_integer(va_list *args);
int			print_unsigned(va_list *args);
int			print_hexadecimal(t_format *fmt, va_list *args);
int			print_pointer(va_list *args);
int			print_percent(t_format *fmt);
#endif // FT_PRINTF_H
