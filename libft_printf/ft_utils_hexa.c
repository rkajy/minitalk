/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:47:04 by radandri          #+#    #+#             */
/*   Updated: 2025/08/24 10:56:44 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Converts an unsigned integer to its hexadecimal representation
 *        and writes it to the standard output.
 *
 * This function handles both lowercase ('x') and uppercase ('X') hexadecimal
 * formats based on the `fmt->type` field. It uses a buffer to store the
 * hexadecimal digits in reverse order and then writes them in the correct
 * order to the output.
 *
 * @param fmt A pointer to a `t_format` structure that specifies the format
 *            type ('x' for lowercase, 'X' for uppercase).
 * @param args A pointer to a `va_list` containing the arguments to be processed.
 *
 * @return The number of characters written to the output on success, or -1
 *         if an error occurs during writing.
 */
int	print_hexadecimal(t_format *fmt, va_list *args)
{
	unsigned int	n;
	char			buffer[16];
	int				i;
	int				count;
	const char		*base;

	base = HEX_BASE;
	if (fmt->type == 'X')
		base = HEX_BASE_CAPITAL;
	n = va_arg(*args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	count = i;
	while (i-- > 0)
		if (write(1, &buffer[i], 1) < 0)
			return (-1);
	return (count);
}
