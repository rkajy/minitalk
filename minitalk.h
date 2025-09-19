/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:19 by radandri          #+#    #+#             */
/*   Updated: 2025/09/19 17:59:02 by radandri         ###   ########.fr       */
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
void				print_binary_array(char *binary, size_t size);
char				*string_message_to_binary(char message[]);
void				send_client_request_to_server(int server_pid,
						char message[]);

// server
void				handler(int sig, siginfo_t *info, void *context);

#endif