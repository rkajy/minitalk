/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:19 by radandri          #+#    #+#             */
/*   Updated: 2025/09/21 12:09:27 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libftprintf/ft_printf.h"
# include <signal.h> // signal, sigemptyset, sigaddset, sigaction, kill
# include <stdlib.h> // malloc, free, exit, atoi
# include <unistd.h> // write, getpid, pause, sleep, usleep

# define BUFFER_SIZE 50000

typedef struct s_data
{
	unsigned char	current_char;
	int				bit_count;
	char			buffer[BUFFER_SIZE];
	int				buf_index;
}					t_data;

// client
void				send_char(int server_pid, char c);
void				send_client_request_to_server(int server_pid,
						char message[]);

// server
void				handler(int sig, siginfo_t *info, void *context);

#endif