/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:46 by radandri          #+#    #+#             */
/*   Updated: 2025/09/16 22:01:51 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char* argv[])
{
    pid_t pid;
    
    pid = getpid();
    ft_printf("The server process ID is %d\n", pid);
    (void) argc;
    (void) argv;
    (void) pid;
    return 0;
}