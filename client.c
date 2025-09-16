/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:34 by radandri          #+#    #+#             */
/*   Updated: 2025/09/16 21:11:36 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    client(int server_pid, char* message[])
{
    (void) server_pid;
    (void) message;
}

int main(int argc, char* argv[])
{
    int server_pid;
    if(argc == 3)
    {
        server_pid = atoi(argv[1]);
        (void) server_pid;
    }
    else{
        ft_printf("Error: Invalid input\n");
        ft_printf("Usage: %s <server_pid> <message_to_send_to_server>\n", argv[0]);
        ft_printf("Eg: %s 12354 \"Hello world\"\n", argv[0]);
        return (1);
    }
    return 0;
}