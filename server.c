/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:46 by radandri          #+#    #+#             */
/*   Updated: 2025/09/21 12:49:19 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Signal handler for reconstructing characters from received bits.
 *
 * This function is used as a signal handler for SIGUSR1 and SIGUSR2.
 * It accumulates bits sent via signals into a static t_data structure,
 * reconstructing characters one bit at a time. When a full character
 * (8 bits) is received, it is stored in a buffer. If a null character
 * ('\0') is received or the buffer is nearly full, the buffer is printed
 * using ft_printf and reset for the next message.
 *
 * @param sig      The signal number received (SIGUSR1 or SIGUSR2).
 * @param info     Pointer to siginfo_t structure.
 * @param context  Pointer to context information.
 */
void	handler(int sig, siginfo_t *info, void *context)
{
	static t_data	data;

	(void)context;
	(void)info;
	data.current_char <<= 1;
	if (sig == SIGUSR2)
		data.current_char = data.current_char | 1;
	data.bit_count++;
	if (data.bit_count == 8)
	{
		data.buffer[data.buf_index++] = data.current_char;
		if (data.current_char == '\0' || data.buf_index >= BUFFER_SIZE - 1)
		{
			data.buffer[data.buf_index] = '\0';
			ft_printf("%s\n", data.buffer);
			data.buf_index = 0;
		}
		data.current_char = 0;
		data.bit_count = 0;
	}
}

/**
 * This function sets up signal handlers for SIGUSR1 and SIGUSR2 using
 * the sigaction API, with a custom handler function. It prints the
 * server's process ID and enters an infinite loop, waiting for signals.
 */
int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("The server process ID is %d\n", pid);
	while (1)
		pause();
	return (0);
}
