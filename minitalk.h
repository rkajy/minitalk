/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:30:19 by radandri          #+#    #+#             */
/*   Updated: 2025/09/18 22:28:06 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libftprintf/ft_printf.h"
# include <signal.h> // signal, sigemptyset, sigaddset, sigaction, kill
# include <stdlib.h> // malloc, free, exit, atoi
# include <unistd.h> // write, getpid, pause, sleep, usleep

// client
void	print_binary_array(char *binary, size_t size);
char	*string_message_to_binary(char message[]);
void	send_client_request_to_server(int server_pid, char message[]);

// server
void	handler(int sig, siginfo_t *info, void *context);

#endif