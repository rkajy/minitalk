/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:34 by radandri          #+#    #+#             */
/*   Updated: 2025/09/18 17:02:07 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_binary_array(char* binary, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        ft_printf("%d", binary[i]);
    }
    ft_printf("\n");
}

char* stringMessageToBinary(char message[])
{
    int i;
    int j;
    int k;
    char* binary;

    binary = malloc(ft_strlen(message) * 8);
    if (!binary)
        return (NULL);
    
    j=0;
    k = 0;
    while (message[j] != '\0')
    {
        i=7;
        while (i >= 0)
        {
            binary[k] = (message[j] >> i) & 1;
            i--;
            k++;
        }
        j++;
    }
    binary[k] = '\0';
    //print_binary_array(binary, ft_strlen(message) * 8);
    return (binary);
}

void    send_client_request_to_server(int server_pid, char message[])
{
    int i;
    char* binary;
    int binary_size;

    ft_printf("Information from client, pid: %d and message to send: \"%s\"\n", server_pid, message);
    
    i=0;
    binary = stringMessageToBinary(message);
    binary_size = ft_strlen(message) * 8;
    while (i < binary_size)
    {
        //send
        if(binary[i] == '0')
            kill(server_pid, SIGUSR1);
        else if(binary[i] == '1')
            kill(server_pid, SIGUSR2);
        i++;
    }
    
}

int main(int argc, char* argv[])
{
    int server_pid;
    char *binary;
    if(argc == 3)
    {
        server_pid = atoi(argv[1]);
        send_client_request_to_server(server_pid, argv[2]);
        binary = stringMessageToBinary("A");

        // don't forget for memory leaks issue
        free(binary);
    }
    else{
        ft_printf("Error: Invalid input\n");
        ft_printf("Usage: %s <server_pid> <message_to_send_to_server>\n", argv[0]);
        ft_printf("Eg: %s 12354 \"Hello world\"\n", argv[0]);
        return (1);
    }
    return 0;
}