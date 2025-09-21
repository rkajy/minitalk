/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:34 by radandri          #+#    #+#             */
/*   Updated: 2025/09/21 12:50:44 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Sends a character to the server bit by bit using signals.
 *
 * Iterates through each bit of the character 'c', from the most significant
 * to the least significant. For each bit, sends a signal to the server
 * identified by 'server_pid':
 * - SIGUSR2 if the bit is 1
 * - SIGUSR1 if the bit is 0
 * Waits 300 microseconds after each signal.
 *
 * @param server_pid PID of the server to send the character to.
 * @param c Character to send.
 */
void	send_char(int server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(300);
		i--;
	}
}

void	send_client_request_to_server(int server_pid, char message[])
{
	int	i;

	ft_printf("Information from client, pid: %d and message to send: \"%s\"\n",
		server_pid, message);
	i = 0;
	while (message[i])
		send_char(server_pid, message[i++]);
	send_char(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	int	server_pid;

	if (argc == 3)
	{
		if (argv[1][0] == '+' || argv[1][0] == '-' || argv[1][0] == '0')
			return (0);
		server_pid = ft_atoi(argv[1]);
		send_client_request_to_server(server_pid, argv[2]);
	}
	else
	{
		ft_printf("Error: Invalid input\n");
		ft_printf("Usage: %s <server_pid> <message_to_send_to_server>\n",
			argv[0]);
		ft_printf("Eg: %s 12354 \"Hello world\"\n", argv[0]);
		return (1);
	}
	return (0);
}
