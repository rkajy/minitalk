/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:34:34 by radandri          #+#    #+#             */
/*   Updated: 2025/08/24 18:39:32 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Converts an unsigned integer to a null-terminated string.
 *
 * This function takes an unsigned integer and converts it into a string
 * representation. The resulting string is dynamically allocated and must
 * be freed by the caller to avoid memory leaks.
 *
 * @param n The unsigned integer to convert.
 * @return A pointer to the dynamically allocated string containing the
 *         string representation of the number. Returns NULL if memory
 *         allocation fails.
 */
static char	*ft_utoa(unsigned int n)
{
	char	buffer[11];
	int		i;
	char	*str;

	i = 10;
	buffer[i] = '\0';
	if (n == 0)
		buffer[--i] = '0';
	while (n > 0)
	{
		buffer[--i] = (n % 10) + '0';
		n /= 10;
	}
	str = ft_strdup(&buffer[i]);
	return (str);
}

/**
 * print_integer - Prints an integer to the standard output.
 * @args: A pointer to a va_list containing the integer to print.
 *
 * This function retrieves an integer from the provided va_list, converts it
 * to a string using the ft_itoa function, and writes the string to the
 * standard output. The function returns the number of characters written
 * or -1 if an error occurs (e.g., memory allocation failure or write error).
 *
 * Return: The number of characters written on success, or -1 on failure.
 */
int	print_integer(va_list *args)
{
	int		n;
	int		count;
	char	*str;

	n = va_arg(*args, int);
	str = ft_itoa(n);
	if (!str)
		return (-1);
	count = ft_strlen(str);
	if (write(1, str, count) != count)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (count);
}

/**
 * @brief Prints an unsigned integer to the standard output.
 *
 * This function retrieves an unsigned integer from the provided `va_list`,
 * converts it to a string representation, and writes it to the standard output.
 * It returns the number of characters printed or -1 in case of an error.
 *
 * @param args A ptr to a `va_list` containing the unsigned integer to print.
 *
 * @return The number of characters printed on success, or
	-1 if an error occurs.
 *
 * @note The function dynamically allocates memory for the string representation
 *       of the nbr using `ft_utoa`. It's the caller's responsibility to ensure
 *       that `ft_utoa` and `ft_strlen` are implemented correctly.
 *
 * @warning If the `write` function fails, the allocated memory is freed,
	and the
 *          function returns -1.
 */
int	print_unsigned(va_list *args)
{
	unsigned int	n;
	int				count;
	char			*str;

	n = va_arg(*args, unsigned int);
	count = 0;
	str = ft_utoa(n);
	if (!str)
		return (-1);
	count = ft_strlen(str);
	if (write(1, str, count) != count)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (count);
}

static int	check_write_error(int fd, const char *buf, size_t count, int ret)
{
	if (write(fd, buf, count) < 0)
		return (-1);
	return (ret);
}

/**
 * print_pointer - Prints a pointer address in hexadecimal format.
 * @args: A pointer to a va_list containing the arguments.
 *
 * This function retrieves a pointer from the provided va_list, converts it
 * to its hexadecimal representation, and writes it to the standard output.
 * The output is prefixed with "0x" to indicate that it is a hexadecimal value.
 * If the pointer is NULL, a predefined string (PTRNULL) is written instead.
 *
 * Return: The total number of characters written on success, or -1 if a
 *         write error occurs.
 *
 * Notes:
 * - The function uses a buffer to store the hexadecimal representation of
 *   the pointer address in reverse order before writing it to the output.
 * - The function handles NULL pointers by writing a specific string and
 *   returning the appropriate count.
 * - The function assumes that HEX_BASE is a predefined string containing
 *   the hexadecimal digits ('0123456789abcdef').
 * - The function uses check_write_error to handle write errors and calculate
 *   the total character count in certain cases.
 */

int	print_pointer(va_list *args)
{
	uintptr_t	ptr;
	int			count;
	char		buffer[16];
	int			i;

	count = 0;
	ptr = (uintptr_t)va_arg(*args, void *);
	if (!ptr)
		return (check_write_error(1, PTRNULL, NPTRSIZE, NPTRSIZE));
	if (write(1, "0x", 2) < 0)
		return (-1);
	count = count + 2;
	if (ptr == 0)
		return (check_write_error(1, "0", 1, count + 1));
	i = 0;
	while (ptr)
	{
		buffer[i++] = HEX_BASE[ptr % 16];
		ptr /= 16;
	}
	count += i;
	while (--i >= 0)
		if (write(1, &buffer[i], 1) < 0)
			return (-1);
	return (count);
}
