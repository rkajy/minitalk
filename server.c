/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:46 by radandri          #+#    #+#             */
/*   Updated: 2025/09/18 22:58:34 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void    handler_binary(int sig, siginfo_t *info, void *context)
// {
//     (void)context;
//     (void)info;
//     if(sig== SIGUSR1)
//         write(1,"0", 1);
//     else if(sig == SIGUSR2)
//         write(1, "1", 1);
// }

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bint_count = 0;

	(void)context;
	(void)info;
	current_char <<= 1;
	if (sig == SIGUSR2)
		current_char = current_char | 1;
	bint_count++;
	if (bint_count == 8)
	{
		write(1, &current_char, 1);
		current_char = 0;
		bint_count = 0;
	}
}

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
	{
		pause();
	}
	return (0);
}
