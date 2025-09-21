/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_az.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:33:06 by radandri          #+#    #+#             */
/*   Updated: 2025/08/24 11:04:22 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * print_char - Prints a single character to the standard output.
 * @args: A pointer to a va_list containing the arguments. The function
 *        expects the next argument in the list to be an integer, which
 *        will be cast to an unsigned char and printed.
 *
 * Return: On success, returns 1 indicating one character was written.
 *         On failure, returns -1 if the write operation fails.
 *
 * Description: This function retrieves the next argument from the
 *              variable argument list, casts it to an unsigned char,
 *              and writes it to the standard output using the write
 *              system call.
 */
int	print_char(va_list *args)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*args, int);
	return (ft_putchar_fd(c, 1));
}

/**
 * @brief Prints a string to the standard output.
 *
 * This function retrieves a string argument from the provided `va_list` and
 * writes it to the standard output using the `ft_putstr_fd` function. If the
 * string argument is `NULL`, it prints the string "(null)" instead.
 *
 * @param args A ptr to the `va_list` containing the string argument to print.
 * @return The number of characters written to the standard output.
 */
int	print_string(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	return (ft_putstr_fd(str, 1));
}

/**
 * @brief Prints a sign ('%') to the standard output if the format type is '%'.
 *
 * This function checks if the format type in the provided `t_format` structure
 * is a percent sign ('%'). If it is, the function writes the '%' character to
 * the standard output using `ft_putchar_fd`. Otherwise, it returns 0 without
 * printing anything.
 *
 * @param fmt A pointer to a `t_format` structure containing the format type.
 *
 * @return The number of characters printed (1 if '%' is printed, 0 otherwise).
 */
int	print_percent(t_format *fmt)
{
	if (fmt->type != '%')
		return (0);
	return (ft_putchar_fd('%', 1));
}
