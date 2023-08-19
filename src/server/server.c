/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:29:38 by cwenz             #+#    #+#             */
/*   Updated: 2023/08/19 15:31:48 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_bit(int signo, siginfo_t *sig_info, void *context);
static void	setup_signal_handler(struct sigaction *action, int signal_type);
static bool	check_sender_pid_changed(siginfo_t *sig_info, char *byte);

int	main(void)
{
	struct sigaction	sa0;
	struct sigaction	sa1;

	ft_printf("Server PID: %d\n", getpid());
	setup_signal_handler(&sa0, SIGUSR1);
	setup_signal_handler(&sa1, SIGUSR2);
	while (1)
		pause();
	return (SUCCESS);
}

static void	setup_signal_handler(struct sigaction *action, int signal_type)
{
	if (signal_type == SIGUSR1)
	{
		action->sa_sigaction = handle_bit;
		sigaddset(&action->sa_mask, SIGUSR2);
	}
	else if (signal_type == SIGUSR2)
	{
		action->sa_sigaction = handle_bit;
		sigaddset(&action->sa_mask, SIGUSR1);
	}
	else
		error_and_exit(FAIL, "Incorrect SIGUSR provided.");
	action->sa_flags = SA_SIGINFO;
	sigaction(signal_type, action, NULL);
}

static void	handle_bit(int signo, siginfo_t *sig_info, void *context)
{
	static int	num_bits_received = 0;
	char		byte;

	if (check_sender_pid_changed(sig_info, &byte))
		num_bits_received = 0;
	byte <<= 1;
	if (sig_info->si_signo == SIGUSR2)
		byte |= 1;
	num_bits_received++;
	if (check_byte_printable(sig_info, &byte, num_bits_received))
		num_bits_received = 0;
	(void)signo;
	(void)context;
}

static bool	check_sender_pid_changed(siginfo_t *sig_info, char *byte)
{
	static int	sender_pid = 0;

	if (sender_pid != sig_info->si_pid)
	{
		sender_pid = sig_info->si_pid;
		*byte = 0;
		return (true);
	}
	return (false);
}
