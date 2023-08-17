/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:29:38 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/17 15:00:24 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_bit_0(int signo, siginfo_t *sig_info, void *context);
static void	handle_bit_1(int signo, siginfo_t *sig_info, void *context);
static void	setup_signal_handler(struct sigaction *action, int signal_type);

int	main(void)
{
	// Print out server PID to use for client
	ft_printf("Server PID: %d\n", getpid());
	// Initialize server data variables
	server_data.byte = 0;
	server_data.num_bits_received = 0;
	setup_signal_handler(&server_data.sa0, SIGUSR1);
	setup_signal_handler(&server_data.sa1, SIGUSR2);
	// Pause the terminal to listen for client input
	while (1)
		pause();
	return (SUCCESS);
}

static void	setup_signal_handler(struct sigaction *action, int signal_type)
{
	if (signal_type == SIGUSR1)
	{
		action->sa_sigaction = handle_bit_0;
		sigaddset(&action->sa_mask, SIGUSR2);
	}
	else if (signal_type == SIGUSR2)
	{
		action->sa_sigaction = handle_bit_1;
		sigaddset(&action->sa_mask, SIGUSR1);
	}
	else
		error_and_exit(FAIL, "Incorrect SIGUSR provided.");
	action->sa_flags = SA_SIGINFO;
	sigaction(signal_type, action, NULL);
}

static void	handle_bit_0(int signo, siginfo_t *sig_info, void *context)
{
	(void)signo;
	(void)context;
	server_data.byte <<= 1;
	server_data.num_bits_received++;
	if (server_data.num_bits_received == 8)
	{
		write(1, &server_data.byte, 1);
		send_signal_back_to_client(sig_info);
		server_data.num_bits_received = 0;
		server_data.byte = 0;
	}
}

static void	handle_bit_1(int signo, siginfo_t *sig_info, void *context)
{
	(void)signo;
	(void)context;
	server_data.byte <<= 1;
	server_data.byte |= 1;
	server_data.num_bits_received++;
	if (server_data.num_bits_received == 8)
	{
		write(1, &server_data.byte, 1);
		send_signal_back_to_client(sig_info);
		server_data.num_bits_received = 0;
		server_data.byte = 0;
	}
}
