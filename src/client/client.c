/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:33:09 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/22 13:53:17 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_bit_to_server(pid_t pid, char bit);
static void setup_confirmation_from_server(void);
static void confirm_bit_sent(int signo);
static void print_acknowledgement(int signo);

int g_server_confirmation;


int main(int argc, char **argv)
{
	int pid;
	int i;
	char *message_in_binary;

	if (argc != 3)
		error_and_exit(FAIL, "Invalid number of command line arguments.");
	i = 0;
	setup_confirmation_from_server();
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			i++;
		else
			error_and_exit(FAIL, "Not a valid PID.");
	}
	pid = ft_atoi(argv[1]);
	message_in_binary = convert_string_to_binary(argv[2]);
	i = 0;
	while (message_in_binary[i])
	{
		send_bit_to_server(pid, message_in_binary[i]);
		i++;
	}
	free(message_in_binary);
	message_in_binary = NULL;
	return (SUCCESS);
}

static void send_bit_to_server(pid_t pid, char bit)
{
	g_server_confirmation = 0;
	if (bit == '0')
		kill(pid, SIGUSR1);
	else if (bit == '1')
		kill(pid, SIGUSR2);
	while (g_server_confirmation == 0)
		continue;
	usleep(100);
}

static void setup_confirmation_from_server(void)
{
	struct sigaction client_sa1;
	struct sigaction client_sa2;

	client_sa1.sa_handler = print_acknowledgement;
	client_sa1.sa_flags = 0;
	sigaction(SIGUSR1, &client_sa1, NULL);
	client_sa2.sa_handler = confirm_bit_sent;
	client_sa2.sa_flags = 0;
	sigaction(SIGUSR2, &client_sa2, NULL);
}

static void confirm_bit_sent(int signo)
{
	(void)signo;
	g_server_confirmation = 1;
}

static void print_acknowledgement(int signo)
{
	(void)signo;
	write(1, "Server recevied message!\n", 26);
}
