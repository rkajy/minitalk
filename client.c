/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:34 by radandri          #+#    #+#             */
/*   Updated: 2025/09/19 20:09:38 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_binary_array(char *binary, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d", binary[i++]);
	}
	ft_printf("\n");
}

char	*string_message_to_binary(char message[])
{
	int		i;
	int		j;
	int		k;
	char	*binary;
	char	c;

	binary = malloc(ft_strlen(message) * 8 + 8 + 1);
	if (!binary)
		return (NULL);
	j = -1;
	k = 0;
	while (message[++j] != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((message[j] >> i--) & 1)
				binary[k] = '1';
			else
				binary[k] = '0';
			k++;
		}
	}
	c = '\0'; //
	i = 7; //
	while (i >= 0) //
	{ // 
		if ((c >> i--) & 1) //
			binary[k] = '1'; //
		else //
			binary[k] = '0'; //
		k++; //
	} //
	binary[k] = '\0';
	return (binary);
}


void	send_client_request_to_server(int server_pid, char message[])
{
	int		i;
	char	*binary;
	int		binary_size;

	ft_printf("Information from client, pid: %d and message to send: \"%s\"\n",
		server_pid, message);
	i = 0;
	binary = string_message_to_binary(message);
	binary_size = ft_strlen(binary) * 8;
	while (i < binary_size)
	{
		if (binary[i] == '0')
			kill(server_pid, SIGUSR1);
		else if (binary[i] == '1')
			kill(server_pid, SIGUSR2);
		i++;
		usleep(300);
	}
	free(binary);
}

int	main(int argc, char *argv[])
{
	int	server_pid;

	if (argc == 3)
	{
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
