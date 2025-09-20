/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:19 by radandri          #+#    #+#             */
/*   Updated: 2025/09/20 13:23:40 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libftprintf/ft_printf.h"
# include <signal.h> // signal, sigemptyset, sigaddset, sigaction, kill
# include <stddef.h>
# include <stdlib.h> // malloc, free, exit, atoi
# include <unistd.h> // write, getpid, pause, sleep, usleep

typedef struct s_data
{
	unsigned char	current_char;
	int				bit_count;
	char			buffer[1024];
	int				buf_index;
}					t_data;

// client
void				send_char(int server_pid, char c);
void				send_client_request_to_server(int server_pid,
						char message[]);

// server
void				handler(int sig, siginfo_t *info, void *context);

#endif