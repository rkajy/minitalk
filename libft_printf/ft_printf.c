/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:38:48 by radandri          #+#    #+#             */
/*   Updated: 2025/08/24 11:02:24 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * handle_format_specifier - Handles the processing of a format specifier
 *                           in a custom printf implementation.
 *
 * @fmt: A pointer to a t_format structure containing the format specifier
 *       details (e.g., type, flags, width, precision).
 * @args: A pointer to the va_list containing the variable arguments to be
 *        processed.
 * @format: A pointer to the current position in the format string being
 *          processed.
 *
 * Return: The number of characters printed as a result of processing the
 *         format specifier.
 *
 * Description:
 * This function determines the type of the format specifier (e.g., 'c', 's',
 * 'd', 'x', etc.) and calls the appropriate helper function to handle the
 * specific type. If the format specifier is invalid, it prints the '%'
 * character followed by the invalid specifier and returns a count of 2.
 *
 * Supported format specifiers:
 * - 'c': Prints a single character.
 * - 's': Prints a string.
 * - 'd' or 'i': Prints a signed integer.
 * - 'u': Prints an unsigned integer.
 * - 'x' or 'X': Prints a hexadecimal number (lowercase or uppercase).
 * - 'p': Prints a pointer address.
 * - '%': Prints a literal '%' character.
 *
 * If the format specifier is not recognized, the function writes the '%'
 * character and the unrecognized specifier to the output.
 */
static int	handle_format_specifier(t_format *fmt, va_list *args,
		const char **format)
{
	int	count;

	count = 0;
	if (fmt->type == 'c')
		count = print_char(args);
	else if (fmt->type == 's')
		count = print_string(args);
	else if (fmt->type == 'd' || fmt->type == 'i')
		count = print_integer(args);
	else if (fmt->type == 'u')
		count = print_unsigned(args);
	else if (fmt->type == 'x' || fmt->type == 'X')
		count = print_hexadecimal(fmt, args);
	else if (fmt->type == 'p')
		count = print_pointer(args);
	else if (fmt->type == '%')
		count = print_percent(fmt);
	else
	{
		write(1, "%", 1);
		write(1, *format, 1);
		count = 2;
	}
	return (count);
}

/**
 * handle_percent - Handles the '%' format specifier in a printf-like function.
 *
 * @format: A pointer to the format string. The pointer is incremented to
 *          process the next character after '%'.
 * @args: A pointer to the list of arguments passed to the printf-like function.
 * @count: The current count of characters written to the output.
 * @fmt: A pointer to a structure containing formatting information.
 *
 * This function processes the '%' character in the format string. If the next
 * character in the format string is a valid format specifier, it delegates the
 * handling to the `handle_format_specifier` function. If the next character is
 * not a valid specifier or the format string ends with '%', it writes the '%'
 * character to the output.
 *
 * Return: The updated count of characters written to the output, or -1 if an
 *         error occurs (e.g., a write operation fails or an invalid specifier
 *         is encountered).
 */
static int	handle_percent(const char **format, va_list *args, int count,
		t_format *fmt)
{
	int	result;

	(*format)++;
	if (**format)
	{
		fmt->type = **format;
		result = handle_format_specifier(fmt, args, format);
		if (result < 0)
			return (-1);
		count += result;
		(*format)++;
	}
	else
	{
		if (write(1, "%", 1) < 0)
			return (-1);
		count++;
	}
	return (count);
}

/**
 * @brief Handles the printing of a single character from the format string.
 *
 * This function writes the current character pointed to by the format string
 * to the standard output and increments the format pointer and the character
 * count. If the write operation fails, it returns -1 to indicate an error.
 *
 * @param format A pointer to the format string pointer. The fctn advances
 *               the ptr to the next character after processing the current one.
 * @param count  The current count of characters successfully written.
 * 
 * @return The updated count of characters written if successful, or -1 if an
 *         error occurs during the write operation.
 */
static int	handle_char(const char **format, int count)
{
	if (write(1, *format, 1) < 0)
		return (-1);
	count++;
	(*format)++;
	return (count);
}

/**
 * @brief Processes a format string and handles formatting directives.
 *
 * This function iterates through the given format string and processes
 * each character. If a '%' character is encountered, it delegates the
 * handling of the format specifier to the `handle_percent` function.
 * Otherwise, it processes the character using the `handle_char` function.
 * The function keeps track of the total count of characters processed.
 *
 * @param format The format string to be processed.
 * @param args A pointer to the variable argument list (va_list).
 * @param count The initial count of characters processed.
 * @param fmt A ptr to a `t_format` structure containing format-specific data.
 * 
 * @return The total count of characters processed, or -1 if an error occurs.
 */
static int	process_format(const char *format, va_list *args, int count,
		t_format *fmt)
{
	while (*format)
	{
		if (*format == '%')
			count = handle_percent(&format, args, count, fmt);
		else
			count = handle_char(&format, count);
		if (count < 0)
			return (-1);
	}
	return (count);
}

/**
 * @brief A custom implementation of the printf function.
 * 
 * This function processes a format string and a variable number of arguments
 * to produce formatted output. It uses a variadic argument list to handle
 * the dynamic number of arguments and relies on helper functions to process
 * the format specifiers.
 * 
 * @param format The format string containing text and format specifiers.
 *               Format specifiers are placeholders for the variable arguments.
 * 
 * @return The total number of characters printed (excluding the null byte).
 *         Returns 0 if no characters are printed.
 * 
 * @note This function uses the `va_list` type and related macros (`va_start`,
 *       `va_end`) to handle variadic arguments. It also relies on a helper
 *       function `process_format` to parse and process the format string.
 */
int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	t_format	fmt;

	count = 0;
	va_start(args, format);
	count = process_format(format, &args, count, &fmt);
	return (va_end(args), count);
}
